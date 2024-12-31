
file1 = "./tests1.txt"
file2 = "./tests2.txt"

with open(file1, 'r', encoding='utf-8') as f1, open(file2, 'r', encoding='utf-8') as f2:
    content1 = f1.read()
    content2 = f2.read()

if content1 == content2:
    print("ファイルは完全に一致しています。")
else:
    print("ファイルは一致していません。")
