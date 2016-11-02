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
                                return false;
                        }
                        gflwMakeContextCurrent(m_Window);
                        return true;
                }
                
                void Window::clear() const
                {
                        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                }

                void Window::update()
                {
                        glfwPollEvents();
                        glfwGetFrameBufferSize(m_Window, &m_Width, &m_Height);
                        glViewport(0, 0, m_Width, m_Height);
                        glfwSwapBuffers(m_Window);
                }
                
                bool Window::closed()
                {
                        glfwWindowShouldClose(m_Window) == 1;
                }
        }
}
