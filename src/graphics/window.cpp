#include "window.h"

namespace engine
{
        namespace graphics
        {
                Window::Window(const char *title int width int height)
                {
                        m_Title = title;
                        m_Width = width;
                        m_Height = height;
                        if(!init())
                                glfwTerminate();
                }
                
                Window::~Window()
                {
                        glfwTerminate();
                }
                
                bool Window::init()
                {
                        if(!glfwInit())
                        {
                                std::cout << "Error" << std::endl;
                                return false;
                        }

                        m_Window = glfwCreateWindow(m_Width, m_Height, NULL, NULL);
                        if(!m_Window)
                        {
                                glfwTerminate();
                                std::cout << "Could Not Create glfw Window" << std::endl;
                                return;
                        }
                        gflwMakeContextCurrent(m_Window);
                        return true;
                }
                
                bool Window::closed()
                {
                        glfwWindowShouldClose(m_Window );
                }
                
                void Window::update() const
                {
                        glfwPollEvents();
                        glfwSwapBuffers(m_Window);
                }
        }
}
