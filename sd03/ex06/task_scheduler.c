#include "task_scheduler.h"

void free_all(struct TaskProfile *profile, struct PriorityMap *priorities,
		struct LoadInfo *load)
{
	if (profile)
		free_task_profile(profile);
	if (priorities)
		free_priority_map(priorities);
	if (load)
		free_loadinfo(load);
}

struct ScheduleResult *schedule_tasks(struct TaskList *tasks)
{
	struct TaskProfile *profile = NULL;
	struct PriorityMap *priorities = NULL;
	struct LoadInfo	*load = NULL;
	struct ScheduleResult *schedule = NULL;
	int core_count = 0;

	profile = profile_tasks(tasks);
	if (!profile)
		return NULL;

	priorities = compute_priorities_mock(profile);
	if (!priorities)
	{
		free_all(profile, priorities, load);
		return NULL;
	}

	core_count = get_available_core_count();
	if (core_count <= 0)
	{
		free_all(profile, priorities, load);
		return NULL;
	}

	schedule = create_schedule_result(core_count);
	if (!schedule)
	{
		free_all(profile, priorities, load);
		return NULL;
	}

	for (int i = 0; i < core_count; i++)
	{
		int task_id = select_best_task(profile);
		if (task_id < 0)
			break;
		update_schedule_entry(schedule, i, task_id);
	}

	free_all(profile, priorities, load);
	return (schedule);
}