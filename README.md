# watch

<img src="D:\soft\else\Tencent\WeChat\WechatFile\WeChat Files\wxid_en3b487n7zeg22\FileStorage\Temp\fd3a2a41aed930bb02453e2b0f487c3.jpg" alt="fd3a2a41aed930bb02453e2b0f487c3" style="zoom:10%;" />

## 硬件
- board:源地stm32f412ret6
- display:达沃科技amoled-1.78寸-368*448

## 问题日志：
- 2024-3-27：使用HAL_Delay卡死
    修改SYStick抢占优先级为4，个人猜测应该是必须比FreeRTOS管理的优先级高才行
- 2024-03-28：屏幕驱动成功，但是颜色出错。
- 2024-03-29：颜色问题解决。
- 2024-04-06：一段时间触摸失效
- 2024-04-06：进入休眠模式，在一个任务中，定时唤醒。
