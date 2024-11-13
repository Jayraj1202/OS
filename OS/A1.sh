#!/bin/bash

create()
{
	echo "Enter Address Book name:"
	read addressbook
	
	res=`ls | grep $addressbook | wc -l`
	if [ $res -gt 0 ]
	then 
	echo 'Error:File already exist'
	else
	touch $addressbook
	echo 'Addresbook book created'
	fi
	
}

display()
{
	echo 'Enter Address book name:'
	read addressbook
	
	res=` ls | grep $addressbook | wc -l`
	
	if [ $res -gt 0 ]
	then
		cat $addressbook
	else
	touch $addressbook
	echo 'Error:Addressbook already exists' 
	fi
}

insert()
{
	echo 'Enter Addressbook name:'
	read addressbook
	
	res=` ls | grep $addressbook | wc -w`
	
	if [ $res -gt 0 ]
	then
		echo 'Enter email'
		read email
		
		#check email present or not
		result=` cat $addressbook | grep $email | wc -w`
		if [ $result -gt 0 ]
		then
		echo 'Error:Email present'
		else
		echo 'Enter first name,last name,mobile number'
		read fname lname mobileno
		
		record=`echo $fname $lname $email $mobileno`
		echo $record >> $addressbook  # single redirection operator(>) means overwrite, >> double means append record
		echo 'record inserted'
	fi
	else
	echo 'Error:file not existing'
	fi

}

modify()
{
	echo 'Enter addressbook name:'
	read addressbook
	
	res=` ls | grep $addressbook | wc -w`
	
	if [ $res -gt 0 ]
	then
		echo 'Enter email'
		read email
		
		result=` cat $addressbook | grep $email | wc -w`
		if [ $result -gt 0 ]
		then
			echo 'Enter Modified data first name,last name,mobile no'
			read fname lname mobileno
			new=`echo $fname $lname $email $mobileno`
			old=`cat $addressbook | grep $email`
			echo "Old record: $old"
			echo " New record:$new"
			
			sed -i s/"$old"/"$new"/g $addressbook
			echo 'Record Modified'
		else
		echo 'Error : Email not exist'
		fi
		
	else
		echo 'Error:file not exist'
	fi
}

delete()
{
	echo 'Enter addressbook name:'
	read addressbook
	
	res=` ls | grep $addressbook | wc -w`
	
	if [ $res -gt 0 ]
	then
	echo 'Enter email'
	read email
	
	result=`cat $addressbook | grep $email | wc -w`
	if [ $result -gt 0 ]
	then
		old=`cat $addressbook | grep $email`
		
		sed -i s/"$old"//g $addressbook
	
		echo 'Record ddeleted'
		
	else
	echo 'Email not exist'
	fi
	
	else
	echo 'File not exist'
	fi
	
}
while [ true ]
do
	echo '***************MENU*****************'
	echo '1. Create'
	echo '2. Display'
	echo '3. Insert'
	echo '4. modify'
	echo '5. delete'
	echo '7. Exit'
	
	echo 'Enter choice'
	read choice
	
	case $choice in
		1) create;;
		
		2) display;;
		
		3) insert;;
		
		4) modify;;
		
		5) delete;;
		
		7) exit;;
		
		*) echo 'Wrong Choice!';;
	
	esac
	
	
	done

