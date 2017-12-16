#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <utility>

struct GLFWwindow;

class Application {
public:
    Application(int width = 800, int height = 600);

    virtual ~Application();

    Application(const Application&) = delete;
    Application& operator=(const Application&) = delete;
    Application(const Application&&) = delete;
    Application& operator=(const Application&&) = delete;

    /**
     * @brief Run the application
     */
    int run();

    /// @brief Virtual function called every frame
    virtual void render() const = 0;

private:
    GLFWwindow* window_;
};


#endif // APPLICATION_HPP
