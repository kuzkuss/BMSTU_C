#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "subject.h"
#include "errors.h"

struct subject_t *create_subject(const char *name, double weight, double volume)
{
    struct subject_t *subject = malloc(sizeof(struct subject_t));
    if (!subject)
        return NULL;
    subject->name = strdup(name);
    if (!subject->name)
    {
        free(subject);
        return NULL;
    }
    subject->weight = weight;
    subject->volume = volume;
    return subject;
}

void free_subject(struct subject_t **psubject)
{
    free((*psubject)->name);
    (*psubject)->name = NULL;
    free(*psubject);
    *psubject = NULL;
}

int subject_read(FILE *f, struct subject_t **psub)
{
    char *tmp = NULL;
    size_t n = 0;
    double weight, volume;
    int rc = getline(&tmp, &n, f);

    if (rc > 0 && strcmp(tmp, "\n") != 0)
    {
        if (fscanf(f, "%lf\n", &weight) == 1 && weight > 0)
        {
            if (fscanf(f, "%lf\n", &volume) == 1 && volume > 0)
                rc = OK;
            else
                rc = INPUT_ERROR;
        }
        else
            rc = INPUT_ERROR;
    }
    else if (rc == -1)
        rc = INPUT_ERROR;
    else
        rc = EMPTY_STRING;

    if (rc == OK)
    {
        *psub = create_subject(tmp, weight, volume);
        if (!(*psub))
            rc = ALLOCATE_ERROR;
    }
    free(tmp);
    return rc;
}

void print_subject(const struct subject_t *psubject)
{
    printf("%s", psubject->name);
    printf("%lf\n", psubject->weight);
    printf("%lf\n", psubject->volume);
}

int cmp_by_density(const void *l_sub, const void *r_sub)
{
    double den_l = ((struct subject_t *)l_sub)->weight / ((struct subject_t *)l_sub)->volume;
    double den_r = ((struct subject_t *)r_sub)->weight / ((struct subject_t *)r_sub)->volume;
    if (fabs(den_l - den_r) < EPS)
        return 0;
    else if (den_l - den_r < 0.0)
        return -1;
    else
        return 1;
}

int sub_copy(struct subject_t *sub_dst, const struct subject_t *sub_src)
{
    char *tmp = strdup(sub_src->name);
    if (!tmp)
        return ALLOCATE_ERROR;
    free(sub_dst->name);

    sub_dst->name = tmp;
    sub_dst->weight = sub_src->weight;
    sub_dst->volume = sub_src->volume;
    return OK;
}

