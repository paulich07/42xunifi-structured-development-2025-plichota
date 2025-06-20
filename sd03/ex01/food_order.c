#include "food_order.h"

// free confirmation structure and its content
void free_confirmation(struct OrderConfirmation *confirmation)
{
    free(confirmation);
}

int process_food_order(struct OrderRequest *request)
{
    struct OrderConfirmation *confirmation;
    int success;
    
    if (!request)
        return (0);

    success = check_restaurant_status(request);

    if (success)
        confirmation = create_standard_confirmation();
    else
        confirmation = create_preorder_confirmation();

    if (!confirmation)
        return (0);
    
    send_confirmation_notification(confirmation);
    free_confirmation(confirmation);
    return (success);
}
