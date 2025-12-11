#question1
string = "My Name is Farooq Ahmad"
vowels = ['a','e','i','o','u']
count = 0
for alphabet in string:
    if alphabet.lower() in vowels:
        count += 1
print(f'vowels in my string are {count}')
