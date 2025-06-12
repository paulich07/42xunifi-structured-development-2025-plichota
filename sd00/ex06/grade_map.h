#ifndef GRADE_MAP_H
# define GRADE_MAP_H

typedef const char *GradeReturn;

typedef GradeReturn GradeMapper(int n);

void map_scores(const int *scores, int size, GradeMapper mapper, const char **mapped_grades);

#endif
