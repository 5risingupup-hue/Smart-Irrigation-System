# 上传到已有 GitHub 仓库

仓库：`https://github.com/5risingupup-hue/Smart-Irrigation-System`  
当前默认分支：`master`（检查时仓库已有 `README.md`、`.gitignore`）

## 推荐：Git 命令上传

1. 从 GitHub 克隆仓库：

```bash
git clone https://github.com/5risingupup-hue/Smart-Irrigation-System.git
cd Smart-Irrigation-System
```

2. 将此压缩包中 `Smart-Irrigation-System/` 内的文件**复制到刚刚克隆的仓库根目录**，合并文件夹。`README.md` 用本次更新版替换；保留 GitHub 原有 `.gitignore`。

3. 检查差异后提交：

```bash
git status
git add README.md firmware docs
git commit -m "docs: add verified Arduino monitoring prototype"
git push origin master
```

`UPLOAD_INSTRUCTIONS.md` 可以不提交到仓库。

## GitHub 网页上传

打开仓库 → `Add file` → `Upload files`，把解压后的 `firmware`、`docs` 等文件拖入上传区域。注意保持目录层级，并更新根目录的 README.md。网页端上传文件夹体验依浏览器而异，推荐用 Git 命令。

## 安全与隐私

- 不上传完整含姓名、学号的课程实验报告；公共仓库可上传本包 `docs/` 中的简要进度记录。
- 不上传 API Key、Wi-Fi 密码、充电宝或设备的个人识别信息。
- 本包没有联网控制代码，后续增加 Wi-Fi 时把私密配置放到 `.gitignore` 排除的本地文件中。
