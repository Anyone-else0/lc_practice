#include "ut.h"

int main(void)
{
    int rc;
    rc = utRun();
    if (rc != 0)
    {
        printf("Ut run failed, rc: %d\n", rc);
    }
    return 0;
}
