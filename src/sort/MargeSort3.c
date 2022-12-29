#include <stdio.h>
#define MAX 10

int angka[MAX];
int memori[MAX];

void merge(int angka[], int memori[], int kiri, int tengah, int kanan)
{
			int i, kiri_akhir, elemen, simpan;
            kiri_akhir = tengah - 1;
            simpan = kiri;
            elemen = kanan - kiri + 1;
            
            while ((kiri <= kiri_akhir) && (tengah <= kanan))
            {
            			if (angka[kiri] <= angka[tengah])
                        {
                                    memori[simpan] = angka[kiri];
                                    simpan = simpan + 1;
                                    kiri = kiri +1;
                        }
                        else
                        {
                        memori[simpan] = angka[tengah];
                        simpan = simpan + 1;
                        tengah = tengah + 1;
                        }
        	}
        	while (kiri <= kiri_akhir)
            {
            			memori[simpan] = angka[kiri];
						kiri = kiri + 1;
						simpan = simpan + 1;	
            }
            while (tengah <= kanan)
            {
            			memori[simpan] = angka[tengah];
            			tengah = tengah + 1;
            			simpan = simpan + 1;
        	}
        	for (i=0; i <= elemen; i++)
            {
            			angka[kanan] = memori[kanan];
            			kanan = kanan - 1;
        	}
}

void m_sort(int angka[], int memori[], int kiri, int kanan)
{
			int tengah;
			if (kanan > kiri)
            {
            			tengah = (kanan + kiri) / 2;
                        m_sort(angka, memori, kiri, tengah);
                        m_sort(angka, memori, tengah+1, kanan);
                        merge(angka, memori, kiri, tengah+1, kanan);
        	}
}

void mergeSort(int angka[], int memori[], int array_size)
{
            m_sort(angka, memori, 0, array_size - 1);
}

int main()
{
            int i;
            printf("Masukkan angka SEBELUM TERURUT : \n");
            for (i = 0; i < MAX; i++)
            {
                        printf ("angka ke %i : ", i+1);
                        scanf ("%d", &angka[i]);
            }

            mergeSort(angka, memori, MAX);
            printf("\nangka SETELAH TERURUT : ");
            for (i = 0; i < MAX; i++)
            printf("%d  ", angka[i]);
            printf("\n");
            return(0);
}


//Reference: https://github.com/rizkyghani16/Marge-Sort/blob/master/Marge.c
