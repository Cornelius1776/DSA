import sys

"""Generate all possible subarrays of a given array using recursion"""

print('using recursion'.upper())


def print_subarray(arr, right, left):
    if left == len(arr):
        return
    elif right > left:
        return print_subarray(arr, 0, left + 1)
    else:
        print(arr[right:left + 1])
        return print_subarray(arr, right + 1, left)


numbers = [3, 1, 2, 5, 6]
print_subarray(numbers, 0, 0)
print('\n')

# Iteration implementation
print('using iteration'.upper())


def sub_arr(arr, size):
    for i in range(0, size):
        for j in range(i, size):
            for k in range(i, j + 1):
                print(f'[{arr[k]}]', end=" ")
            print("\n")


size = len(numbers)
sub_arr(numbers, size)


##########################################
def test(element):
    print(element.upper())


names = ['sam', 'paul', 'ade', 'peter']
for i in range(len(names)):
    print(i, end='. ')
    test(names[i])

# String Operations

# 1. Concatenetion: Joining two or more strings together
word_1 = 'Hi'
word_2 = 'friend'
result = word_1 + ' ' + word_2
print(result)

a = '4'
b = '2'
c = a + b
print(c)

# 2. Substring: a sequence of characters part of a larger string
word_3 = 'Good Morning'
word_4 = word_3[0:6]
print(word_4)

word_4 = word_3[1:3]
print(word_4)

# 3. Indexing: accessing the character of a string using its index
word_5 = 'Hawai'
letter = word_5[2]
print(letter)

letter = word_5[0]
print(letter)

# 4. Insertion: adding a substring to a larger or another string at a specific position
word_6 = result[:3] + 'my awesome'
print(word_6)

word_6 = result[:3] + 'my awesome' + result[2:]
print(word_6)

# 5. Deletion: removing parts of a string
word_7 = word_5[:2] + word_5[5:]
print(word_7)

# 6. Replacement: change parts of a string
word_8 = word_6.replace('friend', 'amigos')
print(word_8)

age: int = 26
print(age)


def fib(num, cache={}):
    if num <= 1:
        return num

    if num in cache:
        return cache[num]

    result = fib(num - 1) + fib(num - 2)
    cache[num] = result
    return result


print(fib(10))
print(fib(20))
print(fib(30))
print(fib(500))


def find_least(arr):
    least = arr[0]
    for i in arr:
        if i < least:
            least = i

    print(least)


num = [23, 54, 2, 54, 76]
find_least(num)


name = "Cornelius"
print(f'The memory size of {name} is {sys.getsizeof(name)} bytes')
