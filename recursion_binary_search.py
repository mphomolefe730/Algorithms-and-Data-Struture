array_of_numbers= []

def arrayadder():
    array_of_numbers.append(input('Enter number to put in array: '))
    print(f'new array = {array_of_numbers}')
    status=input('\nwould you like to continue(y/n)? ')
    if (status == 'y'):
        return arrayadder()
    else:
        return

def binary_search(array_of_numbers,user_number):
    array_of_numbers.sort()
    if len(array_of_numbers)==0:
        print(f'{user_number} is not in array')
    else:
        middle=len(array_of_numbers)//2
        print(f'array of numbers = {array_of_numbers}')
        print(f'index: {middle} \nnumber middle: {array_of_numbers[middle]}\n')
        
        if array_of_numbers[middle] == user_number:
            print(f'{user_number} is in array')  
        else:
            if array_of_numbers[middle]<user_number:
                return binary_search(array_of_numbers[middle+1:], user_number)
            else:
                return binary_search(array_of_numbers[:middle], user_number)
            
arrayadder()
user_number = input('\nwhat number must i check: ')
binary_search(array_of_numbers, user_number)