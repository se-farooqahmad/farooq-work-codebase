#question4
from collections import Counter
dictonary1 = {'a': 100, 'b': 200, 'c':300}
dictionary2 = {'a': 300, 'b': 200, 'd':400}
dictionary = Counter(dictonary1) + Counter(dictionary2)
print(f'the Counter dictionary is {dictionary}')