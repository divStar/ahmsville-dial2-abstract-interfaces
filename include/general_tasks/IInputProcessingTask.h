#ifndef DIAL2_ABSTRACT_INPUTPROCESSINGTASK_H
#define DIAL2_ABSTRACT_INPUTPROCESSINGTASK_H

#include <list>
#include <memory>

/**
 * @namespace   AbstractTasks
 * @brief       Contains all abstract task definitions
 *
 * @author      Igor Voronin
 * @date        10.12.2023
 */
namespace AbstractTasks {

/**
 * @class   IInputProcessingTask
 * @brief   Interface, that defines what an (serial port) input processing task should implement.
 *
 * This interface implements some messages handling while forcing any derived class
 * to implement a parser for the messages it receives.
 *
 * @author  Igor Voronin
 * @date    14.12.2023
 */
class IInputProcessingTask {
public:
  /**
   * @brief Constructor.
   *
   * @param taskName (const char*) short name of the task; it usually is expected to be one or two characters
   */
  explicit IInputProcessingTask(const char *taskName);

  /**
   * @brief Destructor.
   */
  virtual ~IInputProcessingTask() = default;

  /**
   * @return (const char*) the short name of the task
   */
  const char *getTaskName();

  /**
   * @brief IReadInputTask is allowed to access protected members of this class.
   */
  friend class IReadInputTask;

protected:
  /**
   * @brief Short name of the task (e.g. "L", "CP", "SN" etc.).
   */
  const char *taskName;

  /**
   * @brief A shared_ptr (shared pointer) to a list of string (const char*) messages.
   */
  std::shared_ptr<std::list<const char *>> messages;

  /**
   * @brief Sets the internal shared pointer of lists of string messages.
   *
   * @param taskMessages A shared_ptr (shared pointer) to a list of string (const char*) messages
   */
  void setMessages(std::shared_ptr<std::list<const char *>> taskMessages);

  /**
   * @brief Unsets the internal shared pointer of lists of string messages.
   */
  void unsetMessages();

  /**
   * @brief Parses a given string (const char*) message into whatever the task requires.
   *
   * @param message (const char*) string message to parse
   */
  virtual void parseMessage(const char *message) = 0;
};

} // namespace AbstractTasks

#endif //DIAL2_ABSTRACT_INPUTPROCESSINGTASK_H
