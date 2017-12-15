#ifndef WINDOW_HPP
#define WINDOW_HPP

struct GLFWwindow;

class Window {
public:
    Window();

    ~Window();

    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;
    Window(const Window&&) = delete;
    Window& operator=(const Window&&) = delete;

    void render() const;

    void update() const;

    bool should_close() const;
private:
    GLFWwindow* window_;
};


#endif // WINDOW_HPP
