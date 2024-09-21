#!/bin/bash

# 取得當前目錄下的所有資料夾
for dir in */ ; do
    # 移除末尾的 /
    folder_name=$(basename "$dir")
    
    # 檢查資料夾中是否有 domjudge-problem.ini 和 problem.yaml 檔案
    if [[ -f "$dir/domjudge-problem.ini" && -f "$dir/problem.yaml" ]]; then
        # 壓縮該資料夾並命名為該資料夾的名稱
        zip -r "${folder_name}.zip" "$dir"
        echo "壓縮完成: ${folder_name}.zip"
    else
        echo "跳過資料夾: ${folder_name}，因為缺少 domjudge-problem.ini 或 problem.yaml"
    fi
done
