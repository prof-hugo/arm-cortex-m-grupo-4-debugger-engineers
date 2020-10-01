# arm-cortex-m-grupo-4-debugger-engineers
arm-cortex-m-grupo-4-debugger-engineers created by GitHub Classroom

# Exercício 1

A diferença de tempo que estava dando é devido ao uso do vTaskDelay(), que é uma função que faz com que a tarefa seja desbloqueada a partir do tempo que ela foi chamada. O uso do vTaskDelayUntil() é melhor pois ele faz com que a tarefa seja chamada com uma frequencia mais "previsível".
 Isso se dá porque a função vTaskDelay() não leva em consideração o "resto" da função. A vTaskDelayUntil() faz a task voltar no tempo exato que foi definido.
