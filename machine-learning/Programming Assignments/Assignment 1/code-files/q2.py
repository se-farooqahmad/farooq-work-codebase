#question2
lists = [[33, 120], [40], [30, 56, 25], [33, 120], [33], [40]]
newlist = []
for list in lists:
    if list not in newlist:
        newlist.append(list)
print(f'the original list is {lists} \nthe new updated list is {newlist}')