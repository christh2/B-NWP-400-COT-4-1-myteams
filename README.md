EPITECH MyFTP Protocol (RFC959 Extract)

Commandes ne nécessitant pas de connexion préalable:
    /help : code de retour ...
    /login [“user_name”] : 
    /users : 
    /user [“user_uuid”] : 
    /subscribe [“team_uuid”] :
    /unsubscribe [“team_uuid”] :
    /create :
    /list :
    /info :

Commandes nécessitant une connexion préalable :
    /logout : 
    /send [“user_uuid”]: 
    /messages [“user_uuid”] :
    /subscribed ?[“team_uuid”] : 
    /use ?[“team_uuid”] ?[“channel_uuid”] ?[“thread_uuid”] :
    /create [“team_name”] [“team_description”] :
    /create [“channel_name”] [“channel_description”] : 
    /create [“thread_title”] [“thread_message”] : 
    /create [“comment_body”] : 
    /list : 
    /info :
