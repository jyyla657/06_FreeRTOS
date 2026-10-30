/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for Task */
osThreadId_t TaskHandle;
const osThreadAttr_t Task_attributes = {
  .name = "Task",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for Task_G */
osThreadId_t Task_GHandle;
const osThreadAttr_t Task_G_attributes = {
  .name = "Task_G",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow,
};
/* Definitions for Task_R */
osThreadId_t Task_RHandle;
const osThreadAttr_t Task_R_attributes = {
  .name = "Task_R",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow,
};
/* Definitions for Task_Y */
osThreadId_t Task_YHandle;
const osThreadAttr_t Task_Y_attributes = {
  .name = "Task_Y",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow,
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartTask(void *argument);
void StartTask_G(void *argument);
void StartTask_R(void *argument);
void StartTask_Y(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of Task */
  TaskHandle = osThreadNew(StartTask, NULL, &Task_attributes);

  /* creation of Task_G */
  Task_GHandle = osThreadNew(StartTask_G, NULL, &Task_G_attributes);

  /* creation of Task_R */
  Task_RHandle = osThreadNew(StartTask_R, NULL, &Task_R_attributes);

  /* creation of Task_Y */
  Task_YHandle = osThreadNew(StartTask_Y, NULL, &Task_Y_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_StartTask */
/**
  * @brief  Function implementing the Task thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartTask */
void StartTask(void *argument)
{
  /* USER CODE BEGIN StartTask */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END StartTask */
}

/* USER CODE BEGIN Header_StartTask_G */
/**
* @brief Function implementing the Task_G thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask_G */
void StartTask_G(void *argument)
{
  /* USER CODE BEGIN StartTask_G */
  /* Infinite loop */
  for(;;)
  {
    HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_8);
    osDelay(500);
  }
  /* USER CODE END StartTask_G */
}

/* USER CODE BEGIN Header_StartTask_R */
/**
* @brief Function implementing the Task_R thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask_R */
void StartTask_R(void *argument)
{
  /* USER CODE BEGIN StartTask_R */
  /* Infinite loop */
  for(;;)
  {
    HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_9);
    osDelay(700);
  }
  /* USER CODE END StartTask_R */
}

/* USER CODE BEGIN Header_StartTask_Y */
/**
* @brief Function implementing the Task_Y thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask_Y */
void StartTask_Y(void *argument)
{
  /* USER CODE BEGIN StartTask_Y */
  /* Infinite loop */
  for(;;)
  {
    HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_7);
    osDelay(300);
  }
  /* USER CODE END StartTask_Y */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

