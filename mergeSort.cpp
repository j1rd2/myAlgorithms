#include <iostream>
#include <vector>

/*

Actividad 1.4
Divide y venceras | Merge Sort
Sebastian Jimenez Bauer
Jesus Ramirez Delgado

NOTA: hicimos cada quien 1 algoritmo y decidimos colocar ambos.

*/

#include <iostream>

void Merge(int A[], int l, int mid, int h)
{
    int i, j, k;
    int B[h + 1];
    i = l;
    j = mid + 1;
    k = l;
    while (i <= mid && j <= h)
    {
        if (A[i] > A[j])
        {
            B[k++] = A[i++];
        }
        else
        {
            B[k++] = A[j++];
        }
    }
    for (; i <= mid; i++)
    {
        B[k++] = A[i];
    }
    for (; j <= h; j++)
    {
        B[k++] = A[j];
    }
    for (i = l; i <= h; i++)
    {
        A[i] = B[i];
    }
}

void IMergeSort(int A[], int n)
{
    int i, j, k, curr_size, l, h, mid;

    for (curr_size = 1; curr_size <= n - 1; curr_size = 2 * curr_size)
    {
        for (i = 0; i < n - 1; i += 2 * curr_size)
        {
            l = i;
            h = i + 2 * curr_size - 1;
            mid = (l + h) / 2;
            Merge(A, l, mid, std::min(h, n - 1));
        }
    }
}

int main()
{
    int A[] = {5, 2, 7, 6, 2, 1, 0, 3, 9, 4};
    int n = sizeof(A) / sizeof(A[0]);
    int i;

    IMergeSort(A, n);

    for (int i = 0; i < n; ++i)
    {
        std::cout << A[i] << " ";
    }

    return 0;
}


/*

// Función para combinar dos subarreglos ordenados en uno solo
void merge(std::vector<double>& arr, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Crear arreglos temporales
    std::vector<double> L(n1);
    std::vector<double> R(n2);

    // Copiar datos a los arreglos temporales L[] y R[]
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[middle + 1 + j];
    }

    // Combinar los arreglos temporales en uno solo
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] >= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes de L[], si los hay
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes de R[], si los hay
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Función que implementa el algoritmo MergeSort
void mergeSort(std::vector<double>& arr, int left, int right) {
    if (left < right) {
        int middle = left + (right - left) / 2;

        // Dividir y conquistar
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        // Combinar los arreglos ordenados
        merge(arr, left, middle, right);
    }
}


int main() {
    std::vector<double> values1 = {38, 27, 43, 3, 9, 82, 10};  // Example 1
    std::vector<double> values2 = {5, 2, 7, 6, 2, 1, 0, 3, 9, 4};  // Example 2

    mergeSort(values1, 0, values1.size() - 1);
    mergeSort(values2, 0, values2.size() - 1);

    std::cout << "Sorted values for Example 1:" << std::endl;
    for (double val : values1) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "Sorted values for Example 2:" << std::endl;
    for (double val : values2) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    return 0;
}

*/