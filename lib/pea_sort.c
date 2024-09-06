#include "pea_sort.h"

void peaQSort(void *pArray, int left, int right, PeaSortCmp *pfCmp, PeaSortSwap *pfSwap)
{
    if (left >= right) {
        return;
    }
    int pivatPos = left;
    int leftPos = left;
    int rightPos = right;

    while (leftPos < rightPos) {
        if (pivatPos < rightPos) {
            if (pfCmp(pArray, pivatPos, rightPos) <= 0) {
                rightPos--;
            } else {
                pfSwap(pArray, pivatPos, rightPos);
                pivatPos = rightPos;
            }
        }
        if (pivatPos > leftPos) {
            if (pfCmp(pArray, pivatPos, leftPos) >= 0) {
                leftPos++;
            } else {
                pfSwap(pArray, pivatPos, leftPos);
                pivatPos = leftPos;
            }
        }
    }

    peaQSort(pArray, left, pivatPos - 1, pfCmp, pfSwap);
    peaQSort(pArray, pivatPos + 1, right, pfCmp, pfSwap);
    return;
}

static void peaHeapBuild(void *pArray, int left, int right, PeaSortCmp *pfCmp, PeaSortSwap *pfSwap)
{
    int dadPos = left;
    int sonPos = dadPos * 2 + 1;
    while (sonPos <= right) {
        if (sonPos + 1 <= right && pfCmp(pArray, sonPos, sonPos + 1) < 0) {
            sonPos += 1;
        }
        if (pfCmp(pArray, dadPos, sonPos) < 0) {
            pfSwap(pArray, dadPos, sonPos);
        } else {
            break;
        }
        dadPos = sonPos;
        sonPos = dadPos * 2 + 1;
    }
    return;
}

void peaHeapSort(void *pArray, int left, int right, PeaSortCmp *pfCmp, PeaSortSwap *pfSwap)
{
    for (int i = (right + 1) / 2; i >= left; i--) {
        peaHeapBuild(pArray, i, right, pfCmp, pfSwap);
    }
    for (int i = right; i > left; i--) {
        pfSwap(pArray, 0, i);
        peaHeapBuild(pArray, 0, i - 1, pfCmp, pfSwap);
    }
    return;
}
