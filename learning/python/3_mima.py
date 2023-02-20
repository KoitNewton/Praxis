LocalPwd = open('C:\\Users\\abc\Desktop\\mima.txt')
RealPwd = LocalPwd.read()
print('输入你的密码:')
YourPwd = input()
if YourPwd == RealPwd:
    print('密码正确')
else:
    print('密码错误')