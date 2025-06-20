#include "recipe_generator.h"

void free_all(struct Ingredients *ing, struct TasteProfile *tp, struct Recipe *recipe)
{
    if (ing)
        free_ingredients(ing);
    if (tp) 
        free_taste_profile(tp);
    if (recipe)
        free_recipe(recipe);
}

struct Recipe *create_custom_recipe(void)
{
    struct Ingredients *ing = NULL;
    struct TasteProfile *tp = NULL;
    struct Recipe *recipe = NULL;
    int approval = 0;

    ing = get_current_ingredients();
    if (!ing)
    {
        free_all(ing, tp, recipe);
        return (NULL);
    }

    tp = get_user_taste_profile();
    if (!tp)
    {
        free_all(ing, tp, recipe);
        return (NULL);
    }

    recipe = create_recipe(ing, tp);
    if (!recipe)
    {
        free_all(ing, tp, recipe);
        return (NULL);
    }

    approval = get_user_approval(recipe);
    if (!approval)
    {
        free_all(ing, tp, recipe);
        return (NULL);
    }
    return (recipe);
}