# Smart-Irrigation-System

基于 Arduino UNO R3 的单盆智能灌溉系统（课程项目，开发中）。

**当前阶段：环境监测与本地显示已验证；自动灌溉尚未实现。**

## 已完成的验证

| 项目 | 结果 | 证据/代码 |
| --- | --- | --- |
| Arduino UNO R3 程序烧录、Blink | 通过 | `firmware/examples/01_blink/` |
| D8 高电平触发蜂鸣器 | 通过（单独测试） | `firmware/examples/02_buzzer/` |
| SHT3X 环境温湿度采集与串口输出 | 通过 | `firmware/examples/03_sht3x_serial/`、[截图](docs/images/sht3x_serial.png) |
| I²C 总线同时识别 SHT3X 和 OLED | 通过：`0x44`、`0x3C` | `firmware/examples/04_i2c_scanner/`、[截图](docs/images/i2c_scan.png) |
| SHT3X + OLED 温湿度实时显示 | 通过（用户实际显示确认） | `firmware/SmartIrrigationMonitor/` |
| 集成式蜂鸣器异常报警 | 待联合验证 | 不标记为完成 |
| 土壤湿度测量、缺水保护、水泵控制 | 待采购与实现 | 见 [材料清单](docs/bom.md) |
| Python 上位机、Web 监控 | 计划中 | 尚无实际代码 |

**说明：**仓库中的 `.ino` 示例是依据已经完成的 Arduino IDE 测试步骤整理的复现版本，并非从实际电脑中导出的原始草稿。最终测试以实物运行结果为准。不要把未接入的控制功能当作已实现。

## 当前硬件

- Arduino UNO R3 兼容板
- SHT3X-DIS I²C 温湿度模块（扫描地址 `0x44`）
- 0.96 英寸 I²C OLED（扫描地址 `0x3C`，按 SSD1306 128×64 驱动测试）
- 高电平触发蜂鸣器模块（D8）
- 面包板、杜邦线；HW-131 面包板电源模块（目前仅验证可由充电宝供电，**未验证带动水泵**）

接线详见 [docs/wiring.md](docs/wiring.md)。

## 运行当前监测程序

1. 安装 [Arduino IDE](https://www.arduino.cc/en/software)，开发板选择 **Arduino Uno**，选择对应串口（此前测试为 COM9，实际以电脑显示为准）。
2. 在库管理器安装 `Adafruit SHT31 Library`、`Adafruit SSD1306`、`Adafruit GFX Library`（依赖项按 IDE 提示安装）。
3. 按 [接线说明](docs/wiring.md)连接 SHT3X、OLED；拔电接线，确认供电及 GND 无误后再通电。
4. 打开 `firmware/SmartIrrigationMonitor/SmartIrrigationMonitor.ino`，上传。
5. 查看 OLED 温湿度数据，并可在串口监视器选择 `9600 baud` 查看输出。

如果遇到屏幕无显示，先运行 `firmware/examples/04_i2c_scanner/`。I²C 扫描到 `0x3C` 只说明设备应答，不保证所有 OLED 都使用 SSD1306 控制器。

## 目录结构

```text
Smart-Irrigation-System/
├── README.md
├── firmware/
│   ├── SmartIrrigationMonitor/        # 当前运行版：SHT3X + OLED
│   └── examples/                     # 已完成测试的独立复现程序
│       ├── 01_blink/
│       ├── 02_buzzer/
│       ├── 03_sht3x_serial/
│       └── 04_i2c_scanner/
└── docs/
    ├── wiring.md                    # 已有模块接线
    ├── progress.md                  # 阶段进度
    ├── test-results.md              # 实验记录
    ├── bom.md                       # 后续采购计划
    ├── architecture.md              # 规划的系统架构
    └── images/                       # 真实实验截图、概念图
```

## 下一阶段

1. 接入电容式土壤湿度传感器，完成 ADC 采集和干湿标定。
2. 接入两线浮球开关，验证缺水信号和本地保护。
3. 连接 5V 继电器及微型水泵，核对 HW-131 的输出能力、续流保护及电机启动安全。
4. 实现定时/阈值灌溉，再实现分段反馈和最大运行限制。
5. 接入 Python 串口网关、历史记录和 Web 监控。

## 资料与说明

- [阶段进展](docs/progress.md) · [测试记录](docs/test-results.md) · [系统设计](docs/architecture.md)
- [Arduino 官方文档](https://docs.arduino.cc/)
- [Adafruit SHT31 Library](https://github.com/adafruit/Adafruit_SHT31)
- [Adafruit SSD1306 Library](https://github.com/adafruit/Adafruit_SSD1306)

`docs/images/product_concept.png` 为**产品概念效果图，并非实物照片**。仓库不包含含姓名、学号等个人信息的完整实验报告。
