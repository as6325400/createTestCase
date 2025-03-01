import os

def output(case_name):
    # 使用'r'模式讀取輸入檔案
    with open(case_name, 'r') as input_file:
        # 讀取檔案內容（如果需要的話）
        content = input_file.read()

    # 移除檔案名的最後三個字符（".in"）並添加".ans"後綴
    output_name = case_name[:-3] + ".ans"
    a, b = map(int, content.split())
    # 使用'w'模式寫入輸出檔案
    with open(output_name, 'w') as output_file:
        # 寫入到輸出檔案（這裡假設直接寫入讀取的內容，可根據需要修改）
        output_file.write(str(a * b))

def main():
    path = "../data/"
    # 處理樣本測試案例
    output(os.path.join(path, "sample/", "1.in"))
    output(os.path.join(path, "sample/", "2.in"))
    # 處理秘密測試案例
    test_case_name = 11
    for i in range(3, test_case_name + 1):
        filename = os.path.join(path, "secret/", f"{i}.in")
        output(filename)

if __name__ == "__main__":
    main()
