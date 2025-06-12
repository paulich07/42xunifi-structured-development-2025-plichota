#include "food_order.h"

// free confirmation structure and its content
void free_confirmation(struct OrderConfirmation *confirmation)
{
    free(confirmation);
}

int process_food_order(struct OrderRequest *request)
{
    OrderConfirmation *confirmation;

    if (!request)
        return (0);

    if (check_restaurant_status(request))
        confirmation = create_standard_confirmation();
    else
        confirmation = create_preorder_confirmation();

    if (!confirmation)
        return (0);
    
    send_confirmation_notification(confirmation);
    return (free_confirmation(confirmation), 1);
}
