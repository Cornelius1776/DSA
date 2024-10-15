#include <iostream>
#include <vector>
/* std::vector is an STL container that behaves like a dynamic array, this means that the size can
grow and shrink dynamically. This is possible because there is no need to specify the size of the
elements at compile time. Vector provide the best of both linked list and arrays,  by providing
non-contigious memory allocation and accessing element in constant time O(1).*/

template <typename T>
void print_vec(const std::vector<T> &vec)
{
    for (size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void print_raw_array(const T *p, std::size_t size)
{
    std::cout << "data = ";
    for (std::size_t i = 0; i < size; ++i)
        std::cout << p[i] << ' ';
    std::cout << std::endl;
}

int main()
{

    // Constructing vectors
    std::vector<std::string> vec_str = {"The", "sky", "is", "blue", "my", "friend"};
    std::cout << "vec_str : " << vec_str[1] << std::endl;
    print_vec(vec_str);

    std::cout << std::endl;

    std::vector<int> ints_1;
    std::cout << "ints_1 : ";
    print_vec(ints_1); // Won't print anything, the vector has no content

    std::vector<int> ints_2 = {1, 2, 3, 4};
    std::vector<int> ints_3 = {11, 22, 33, 44};

    std::cout << "ints_2 : ";
    print_vec(ints_2);

    std::cout << "ints_3 : ";
    print_vec(ints_3);

    // Range based declaration.
    std::vector<int> ints_4(20, 55); // A vector with 20 items, all initialized to 55
    std::cout << "ints_4 : ";
    print_vec(ints_4);

    // uniform initialization will not do the same
    std::vector<int> ints_5 = {20, 55}; // A vector with 2 items : 20 and 55
    std::cout << "ints_5 : ";
    print_vec(ints_5);

    // Accessing elements
    std::cout << std::endl;
    std::cout << "Accessing elements in a vector: " << std::endl;
    std::cout << "vec_str[2] : " << vec_str[2] << std::endl;
    std::cout << "vec_str.at(3) : " << vec_str.at(3) << std::endl;
    std::cout << "vec_str.front() : " << vec_str.front() << std::endl;
    std::cout << "vec_str.back() : " << vec_str.back() << std::endl;
    std::cout << std::endl;

    // Using the data method
    std::cout << "using raw array : " << std::endl;
    print_raw_array(vec_str.data(), vec_str.size());

    // Adding and removing stuff
    std::cout << std::endl;
    std::cout << "Adding and removing stuff : " << std::endl;

    std::cout << "ints_1 : ";
    print_vec(ints_1);

    // Pushing back
    ints_1.push_back(100);
    ints_1.push_back(200);
    ints_1.push_back(300);
    ints_1.push_back(500);

    std::cout << "ints1 : ";
    print_vec(ints_1);

    // Poping back
    ints_1.pop_back();
    std::cout << "ints1 : ";
    print_vec(ints_1);

    // size vs capacity in vector
    std::vector<int> my_vec;
    int count = 50;
    std::string vec_size = "the vector size is ";
    std::string vec_capacity = "The vector capacity is ";
    for (size_t i = 0; i < count; i++)
    {
        my_vec.push_back(i);
        std::cout << vec_size << my_vec.size() << " " << vec_capacity << my_vec.capacity() << "\n";
    }
    std::cout << std::endl;

    /* reserve() method can be used to make things easy for the computer to execute by removing
    the array doubling operation of increasing the capacity. simply do reserve(1000) etc. If the
    reserve is exceeded, the vector capacity will double the reserve.*/

    std::cout << "Using reserve() " << std::endl;
    std::vector<int> test;
    test.reserve(50);
    for (size_t i = 0; i < 100; i++)
    {
        test.push_back(i);
        std::cout << vec_size << test.size() << " " << vec_capacity << test.capacity() << "\n";
    }
    std::cout << std::endl;

    /* Vectors can contain vectors, and this is true for all the containers. Container can
    contain other containers also */

    std::vector ints_6 = {23, 45, 43, 5};
    print_vec(ints_6);

    std::vector<std::vector<int>> tree;
    int edge, sub_1, sub_2;

    std::cout << "How many edges?: " << std::endl;
    std::cin >> edge;
    tree.resize(edge);
    for (size_t i = 0; i < edge; i++)
    {
        std::cin >> sub_1 >> sub_2;
        tree[sub_1].push_back(sub_2);
        /* The first input is the element of the outer vector(it is a vector in itself), while
        the second input is that of the second vector. */
    }
    std::cout << "\n";
    for (auto &&inner_vector : tree)
    {
        for (auto &&element : inner_vector)
        {
            std::cout << element << " ";
        }

        std::cout << std::endl;
    }

    return 0;
}