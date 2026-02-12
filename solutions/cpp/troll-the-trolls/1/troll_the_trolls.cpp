namespace hellmath {
    enum AccountStatus {
        troll,
        guest,
        user,
        mod
    };

    enum Action {
        read,
        write,
        remove
    };

    bool display_post(AccountStatus poster, AccountStatus viewer) {
        return poster != troll or viewer == troll;
    }

    bool permission_check(const Action action, const AccountStatus current_user) {
        switch (current_user) {
            case guest:
                return action == read;
            case troll:
            case user:
                return action != remove;
            case mod:
                return true;
            default:
                return false;
        }
    }


    bool valid_player_combination(AccountStatus player1, AccountStatus player2) {
        switch (player1) {
            case troll:
                return player2 == troll;
            case user:
            case mod:
                return player2 == user or player2 == mod;
            default:
                return false;
        }
    }

    bool has_priority(AccountStatus player1, AccountStatus player2) {
        return player1 > player2;
    }
} // namespace hellmath
