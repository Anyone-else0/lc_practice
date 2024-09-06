#ifndef __PEA_SORT_H__
#define __PEA_SORT_H__

typedef int (PeaSortCmp)(void *pArray, int pos1, int pos2);
typedef void (PeaSortSwap)(void *pArray, int pos1, int pos2);

void peaQSort(void *pArray, int left, int right, PeaSortCmp *pfCmp, PeaSortSwap *pfSwap);
void peaHeapSort(void *pArray, int left, int right, PeaSortCmp *pfCmp, PeaSortSwap *pfSwap);

#endif