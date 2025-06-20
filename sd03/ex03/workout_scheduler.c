#include "workout_scheduler.h"

void free_all(struct UserData *user, struct WorkoutPlan *basePlan)
{
    if (user)
        free_user_data(user);
    if (basePlan)
        free_workout_plan(basePlan);
}

struct WorkoutPlan *create_workout_schedule(char *username)
{
    struct UserData *user = NULL;
    struct WorkoutPlan *basePlan = NULL;

    if (!username)
        return (NULL);
    // get user info
    user = get_user_data(username);
    if (!user)
        return (NULL);

    // build plan
    basePlan = build_base_plan(user);
    if (!basePlan)
    {
        free_all(user, NULL);
        return (NULL);
    }

    // refine plan
    basePlan = refine_plan(basePlan, user);
    if (!basePlan)
    {
        free_all(user, basePlan);
        return (NULL);
    }

    // determine duration
    int days = determine_duration(basePlan);
    if (days <= 0)
    {
        free_all(user, basePlan);
        return (NULL);
    }

    for (int i = 0; i < days; i++)
    {
        assign_daily_exercises(basePlan, i);
        assign_daily_tips(basePlan, i);
    }
    return (basePlan);
}