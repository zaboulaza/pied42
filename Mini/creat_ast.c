/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_ast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsmail <nsmail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:24:54 by nsmail            #+#    #+#             */
/*   Updated: 2025/09/17 23:21:19 by nsmail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

t_cmd	*init_ast_exemple(t_cmd *cmd, bool mini_ast_pipe) {

    if (cmd->next == NULL) {
        return cmd;
    }

    t_cmd *operateur = cmd->next;
    operateur->left = cmd;

    return (creat_ast_exemple(operateur, mini_ast_pipe));
}

bool a_moins_de_priorite(t_cmd *operateur, t_cmd *next_operateur)
{
    return operateur > next_operateur
}


t_cmd	*creat_ast_exemple(t_cmd *operateur, bool mini_ast_pipe) {

    t_cmd *next_commande = operateur->next;
    t_cmd *next_operateur = operateur->next->next;

    if (next_operateur == NULL) {
        operateur->right = next_commande;
        return operateur; // ast/mini_ast fini
    }

    if (mini_ast_pipe
    && (next_operateur->type == AND || next_operateur->type == OR)) {
        operateur->right = next_commande;
        return operateur;
    } //  mini_ast fini 

    if (priorite(operateur) < priorite(next_operateur)) 
    {
        operateur->right = init_ast_exemple(next_commande, true);// cree mini ast 
        next_operateur = next_operateur_non_utilise(next_commande);// mini_ast fini et find next AND / OR / NULL
        if (next_operateur == NULL)  // si find = NULL
            return operateur; // ast fini
    } 
    else {
        operateur->right = next_commande;
    }

    next_operateur->left = operateur;

    return (creat_ast_exemple(next_operateur, false));
}


// t_cmd	*init_ast_exemple(t_cmd *cmd) {

//     if (/* une seule commande */) {
//         return cmd;
//     }

//     t_cmd *operateur = cmd->next;
//     operateur->left = cmd;

//     return (creat_ast_exemple(operateur));
// }

// t_cmd	*creat_ast_exemple(t_cmd *operateur) {
    
    
//     operateur->right = operateur->next;

//     t_cmd *next_operateur = operateur->next->next;

//     // si pas d'autre operateur
//     if (next_operateur == NULL) {
//         return operateur;
//     }
    
//     next_operateur->left = operateur;

//     return (creat_ast_exemple(next_operateur));
// }
