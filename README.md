<p align="center">
<img  style="width:50%;"  alt="Logo" src="assets/picture/main_logo.png">
<br>
<em>稳定 易用 精度</em>
<br>
</p>
<p align="center">
<a href="README_EN.md">English</a>
</p>

---

# 🚀 [一个简单易用的多传感器同步方案](https://github.com/InfiniteSenseLab/SimpleSensorSync/wiki)！  
   多传感器的时间同步是一个很重要的问题，尤其对多传感器融合系统。不正确的时间同步会导致数据融合错误，影响系统性能。 对大多数研究人员来说，这是一个底层又复杂的问题，却不是他们的研究方向。更多的精力应该放在设计传感器融合算法上，而不是在时间同步上。因此，我们设计了这样一个系统，让时间同步不再是一件难事。  
   
<p align="center">
  <img alt="Image 1" src="assets/picture/v4_board.png" width="45%">
  &nbsp;&nbsp;&nbsp;
  <img alt="Image 2" src="assets/picture/link/all_sensor.png" width="45%">
</p>   

---
✨ 精简依赖 – 降低编译开销，构建更快速。  
🤖 支持 ROS2 & Python – 轻松集成现代机器人与脚本化工作流。  
⏱ 更精准的同步机制 – 提供更高精度的时间协调。  
📡 数据协议更透明(JSON) – 通信更清晰、更灵活。  
⚙️ 配置更简单 – 轻松上手，自定义更便捷。  
📜 日志功能增强 – 记录更全面，调试更高效。   
🌐 多平台灵活部署 – (ZeroMQ)支持嵌入式/桌面/云端多场景部署。  
🔗 支持多相机 📷、多雷达⦿ 、IMU 🧭 与 GPS 🛰 的混合信号协同管理。  
🔄 支持多同步板 -V3/V4/MINI。  
🛡️ 安全可靠 – 更加安全的电源与接线🚫。

# News

>1. 2026年9月16号后版本中板载IMU更换成42670P。
>2. 上线自动配置工具,推荐Chorme浏览器打开[imaginative-fenglisu-9fcdf0.netlify.app](https://imaginative-fenglisu-9fcdf0.netlify.app/)
>3. 新pyhton版本使用说明文档。
>4. 增加触发引脚电流12mA，提高引脚驱动能力。
>5. 支持脉冲占空比调节。
>6. 板载IMU频率(航姿解算)提高200HZ。
>7. 完整的[使用说明与系统说明](https://github.com/InfiniteSenseLab/SimpleSensorSync/wiki)发布。
>8. Python-SDK发布，同步可视化工具发布。

<table>
<tr>
<td align="center">
<img src="https://github.com/user-attachments/assets/6787bf44-0433-4cee-9843-9e48ebab3e41" width="400">
</td>

<td align="center">
<img src="assets/picture/web.png" width="400">
</td>
</tr>
</table>

# 支持设备

>| 设备类型        | 品牌                            |同步方式 |
>|-------------|-------------------------------|--------|
>| 工业相机(网口)    | 海康/华睿/大恒/京航/PointGrey/Basler/...               | PWM    |
>| 工业相机(USB)   | 海康/华睿/大恒/京航/PointGrey/Basler/...               | PWM    |
>| 特殊相机   | OAK/...               | PWM    |
>| 第三方IMU      | Xsense系列/HiPNUC...                 | PWM    |
>| 3D激光        | Mid360/Mid70/RoboSense/Tele-15/Horizon系列/Ouster/...  | PPS   |
>| RTK/GPS/组合导航    | 所有支持NMEA0183设备                | NMEA   |
>| 主机(ARM/X86) | Intel/AMD/Jetson/RockChip/... | PTP    |


# 咨询

[【淘宝】「多相机同步IMU激光雷达Mid360硬件同步板GPS网口串口工业相机ROS」
点击链接直接打开 或者 淘宝搜索直接打开](https://item.taobao.com/item.htm?abbucket=20&id=832624497202&mi_id=0000hMPUBSVCRAYonU3gjxDgfdY-8yA6by6IijyfYwEQCjc&ns=1&priceTId=214787c217683999683236296e0ff7&skuId=5934998856763&spm=a21n57.1.hoverItem.1&utparam=%7B%22aplus_abtest%22%3A%229758fee20f89c46fbabfb29784cc8409%22%7D&xxc=taobaoSearch)

# 感谢  

同步板已经被越来越多的小伙伴使用 🎉    欢迎大家多提建议、创建 Issues 🛠️📝 一起让它变得更好！如果觉得不错，别忘了点个 ⭐ 

