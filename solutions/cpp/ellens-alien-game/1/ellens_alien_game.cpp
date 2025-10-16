namespace targets {
    class Alien {
    public:
        Alien(double x, double y) {
            x_coordinate = x;
            y_coordinate = y;
        }

        double x_coordinate{};
        double y_coordinate{};

        int get_health() {
            return this->health;
        }

        bool hit() {
            if (this->health > 0) {
                this->health -= 1;
            }
            return true;
        }

        bool is_alive() {
            return this->health > 0;
        }

        bool teleport(int x, int y) {
            this->x_coordinate = x;
            this->y_coordinate = y;
            return true;
        }

        bool collision_detection(Alien other) {
            return this->x_coordinate == other.x_coordinate and
                   this->y_coordinate == other.y_coordinate;
        }

    private:
        int health{3};
    };
} // namespace targets
