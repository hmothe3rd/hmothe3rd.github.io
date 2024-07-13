#include <iostream>
#include <vector>
#include <algorithm>

void BubbleSort(std::vector<int> &vec)
{
    bool swapped;
    do
    {
        swapped = false;
        for (int i = 0; i < vec.size() - 1; i++)
        {
            if (vec[i] > vec[i + 1])
            {
                std::swap(vec[i], vec[i + 1]);
                swapped = true;
            }
        }
    } while (swapped);
}

void InsertionSort(std::vector<int> &vec)
{
    for (int i = 1; i < vec.size(); i++)
    {
        int key = vec[i];
        int j = i - 1;
        while (j >= 0 && vec[j] > key)
        {
            vec[j + 1] = vec[j];
            --j;
        }
        vec[j + 1] = key;
    }
}

void Heapify(std::vector<int> &vec, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && vec[left] > vec[largest])
        largest = left;

    if (right < n && vec[right] > vec[largest])
        largest = right;

    if (largest != i)
    {
        std::swap(vec[i], vec[largest]);
        Heapify(vec, n, largest);
    }
}

void HeapSort(std::vector<int> &vec)
{
    int n = vec.size();

    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify(vec, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        std::swap(vec[0], vec[i]);
        Heapify(vec, i, 0);
    }
}

void QuickSort(std::vector<int> &vec, int low, int high)
{
    if (low < high)
    {
        int pivot = vec[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++)
        {
            if (vec[j] < pivot)
            {
                i++;
                std::swap(vec[i], vec[j]);
            }
        }
        std::swap(vec[i + 1], vec[high]);
        QuickSort(vec, low, i);
        QuickSort(vec, i + 2, high);
    }
}

void Merge(std::vector<int> &vec, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = vec[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = vec[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            vec[k] = L[i];
            i++;
        }
        else
        {
            vec[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        vec[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        vec[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(std::vector<int> &vec, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        MergeSort(vec, left, mid);
        MergeSort(vec, mid + 1, right);

        Merge(vec, left, mid, right);
    }
}

// Selection Sort
void SelectionSort(std::vector<int> &vec)
{
    for (size_t i = 0; i < vec.size(); ++i)
    {
        size_t minIdx = i;
        for (size_t j = i + 1; j < vec.size(); ++j)
        {
            if (vec[j] < vec[minIdx])
                minIdx = j;
        }
        std::swap(vec[minIdx], vec[i]);
    }
}

void ShellSort(std::vector<int> &vec)
{
    for (int gap = vec.size() / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < vec.size(); i++)
        {
            int temp = vec[i];
            int j;
            for (j = i; j >= gap && vec[j - gap] > temp; j -= gap)
            {
                vec[j] = vec[j - gap];
            }
            vec[j] = temp;
        }
    }
}

void PrintVector(std::vector<int> &vec)
{
    for (int num : vec)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> vec;
    int n, val;

    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    std::cout << "Enter the elements: \n";
    for (int i = 0; i < n; i++)
    {
        std::cin >> val;
        vec.push_back(val);
    }

    std::vector<int> vec1 = vec;
    std::cout << "Bubble Sort: ";
    BubbleSort(vec1);
    PrintVector(vec1);

    std::vector<int> vec2 = vec;
    std::cout << "Insertion Sort: ";
    InsertionSort(vec2);
    PrintVector(vec2);

    std::vector<int> vec3 = vec;
    std::cout << "Heap Sort: ";
    HeapSort(vec3);
    PrintVector(vec3);

    std::vector<int> vec4 = vec;
    std::cout << "Quick Sort: ";
    QuickSort(vec4, 0, vec4.size() - 1);
    PrintVector(vec4);

    std::vector<int> vec5 = vec;
    std::cout << "Merge Sort: ";
    MergeSort(vec5, 0, vec5.size() - 1);
    PrintVector(vec5);

    std::vector<int> vec6 = vec;
    std::cout << "Selection Sort: ";
    SelectionSort(vec6);
    PrintVector(vec6);

    std::vector<int> vec7 = vec;
    std::cout << "Shell Sort: ";
    ShellSort(vec7);
    PrintVector(vec7);
}