#! python3
# pw.py - An insecure password locker program.
PASSWORDS = {'email': 'F7minlBDDuvMJuxESSKHFhTxFtjVB6',
            'blog': 'VmALvQyKAxiVH5G8v01if1MLZF3sdt',
            'luggage': '12345'}
import sys, pyperclip
print(sys.argv)
print(len(sys.argv))
if len(sys.argv) < 2:
    print('Usage: py pw.py [account] - copy account password')
    sys.exit()

account = sys.argv[1] # first command line arg is the account name
if account in PASSWORDS:
    pyperclip.copy(PASSWORDS[account])
    print('Password for ' + account + ' copied to clipboard.')
else:
    print('There is no account named ' + account)

'''
just like this:
PS F:\Github\Praxis> & E:/python311/python.exe f:/Github/Psraxis/learning/python/7_account.py email
['f:/Github/Praxis/learning/python/7_account.py','email']
2
Password for email copied to clipboard.
'''

'''
其实就是python.exe后面的参数
'''