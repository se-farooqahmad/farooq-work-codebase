#question3
mytuple = [(), (), ('',), ('a', 'b'), ('a', 'b', 'c'), ('d')]
tuples = [value for value in mytuple if value]
print(f'the original tuple list is {mytuple} \nthe new updated tuple list is {tuples}')