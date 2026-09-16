#include "video_cam.h"
#include "infinite_sense.h"
namespace infinite_sense {


VideoCam::VideoCam(const std::vector<std::pair<std::string, int>>& cam_list)
{
  cam_lists_ = cam_list;
}

// 调用停止读取函数
VideoCam::~VideoCam() { Stop(); }

// 初始化摄像头
bool VideoCam::Initialization() {
    std::lock_guard lock(cap_mutex_);
    for (auto& cam : cam_lists_) {
        const std::string& name = cam.first;
        int device_id = cam.second;

        cv::VideoCapture cap;
        if (!cap.open(device_id)) {
              std::cerr << "[OpenCVCam] Failed to open camera: " 
                        << name << " (id=" << device_id << ")" << std::endl;
              return false;
        }
        cap.set(cv::CAP_PROP_FPS, 30);
        caps_[name] = std::move(cap);
        std::cout << "[OpenCVCam] Camera " << name << " initialized." << std::endl;
    }
    is_initialized_ = true;
    return true;
}

// 停止读取函数 
void VideoCam::Stop() {
    is_running = false;
    {
        std::lock_guard lock(cap_mutex_);
        for (auto& kv : caps_) {
            if (kv.second.isOpened()) {
                kv.second.release();
                std::cout << "[OpenCVCam] Camera " << kv.first << " released." << std::endl;
            }
        }
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    for (auto& t : cam_threads_) {
        if (t.joinable()) {
            t.join();
        }
    }
    cam_threads_.clear();
    cam_threads_.shrink_to_fit();
}

// 相机读取函数 
void VideoCam::Receive(void *handle, const std::string &name) {
    CamData cam_data;
    Messenger &messenger = Messenger::GetInstance();

    while (is_running) {
        cv::Mat frame_bgr;
        {
            std::lock_guard lock(cap_mutex_);
            auto it = caps_.find(name);
            if (it == caps_.end() || !it->second.isOpened() || !it->second.read(frame_bgr)) {
                std::cerr << "[OpenCVCam] Failed to read frame from: " << name << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(5));
                continue;
            }
        }

        // 获取时间戳
        if (params.find(name) == params.end()) {
            LOG(ERROR) << "cam: " << name << " not found!";
        } else {
            if (uint64_t time; GET_LAST_TRIGGER_STATUS(params[name], time)) {
                cam_data.time_stamp_us = time;
            } else {
                LOG(ERROR) << "Trigger cam: " << name << " not found!";
            }
        }

        cam_data.name = name;
        cam_data.image = GMat(frame_bgr.rows, frame_bgr.cols,
                              GMatType<uint8_t, 3>::Type, frame_bgr.data).Clone();

        messenger.PubStruct(name, &cam_data, sizeof(cam_data));
        std::this_thread::sleep_for(std::chrono::milliseconds{2});
    }
}

// 开始读取函数
void VideoCam::Start() {
    if (!is_initialized_) {
        std::cerr << "[OpenCVCam] Start failed: not initialized." << std::endl;
        return;
    }

    is_running = true;
    {
        std::lock_guard lock(cap_mutex_);
        for (auto& kv : caps_) {
            cam_threads_.emplace_back(&VideoCam::Receive, this, nullptr, kv.first);
            std::cout << "[OpenCVCam] Camera " << kv.first << " capture started." << std::endl;
        }
    }
}
}  // namespace infinite_sense
