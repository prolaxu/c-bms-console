User Manual:
<br>
This program is designed for the bank staff to easily manage the banking transactions.<br>
Firstly, We need to login into system .The default login credential is:<br>
<br>
User Name:admin<br>
Password:pass123<br>
<br>
In the main program you will get all the options for:<br>
<ul>
 <li>Create New Account  [To Create new account]<br>
We need to enter basic information asked to be filed by program and the account will be created and stored in a db file.<br>
It will print out the account number and store it safely because it will be used in future operations.<br>
 </li>

 <li>Account Enquiry        [To Show account data]<br>
We need to enter the account on which we get while creating the account and it will print out all the info of the account.<br>
</li>
 <li>Customer List            [To List Accounts]<br>
Just select this action and it will print out all the lists of accounts.<br>
</li>
<li> All Transactions         [To show all Transactions]<br>
Just select this action and it will print out all the lists of recent transactions.<br>
</li>
<li> Doposit                      [To Deposit balance in Account]<br>
We need to enter account number and amount to deposit and the account will be updated and take the case from the account holder.<br>
</li>

<li> Withdraw                   [To Withdraw balance in account]<br>
 We need to enter account number and amount to deposit and the account will be       updated and give the case from the account holder.<br>
</li>
<li> Transfer                     [To transfer balance from one account to another]<br>
We need to enter the Drawback account number from which balance is to be transferred ,amount to be transferred and account number of account in which balance is to be transferred.<br><li>
<li>
 Exit                            [To end the program]<br>
Finally select this action to end the program.<br>
 </li>
 </ul>
<br>
File tree:<br>
├── db<br>
│   ├── accounts.db<br>
│   ├── admin.db<br>
│   └── transations.db<br>
├── main.c<br>



