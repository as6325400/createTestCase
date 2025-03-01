import os
import random

# 設置隨機數生成器的種子值
random.seed()

# 指定案例數量
testCaseNum = 10

# 路徑前綴，用於保存檔案
path = "../data/secret/"

# 確保目標目錄存在
os.makedirs(path, exist_ok=True)

# 生成指定範圍內的檔案
for i in range(3, testCaseNum + 1):
    filename = os.path.join(path, f"{i}.in")
    
    # 使用with語句來自動處理檔案開啟和關閉
    with open(filename, 'w') as inputFile:
        rng = random.SystemRandom()
        len1 = rng.randint(1, 100)
        len2 = rng.randint(1, 100)
        random_number_str1 = ''.join(str(rng.randint(0, 9)) for _ in range(len1))
        random_number_str2 = ''.join(str(rng.randint(0, 9)) for _ in range(len2))
        # 將字符串轉換為整數
        random_number1 = int(random_number_str1)
        random_number2 = int(random_number_str2)
        inputFile.write(f"{random_number1} {random_number2}\n")


