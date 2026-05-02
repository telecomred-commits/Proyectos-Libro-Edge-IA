
#ifndef AIR_TREE_MODEL_H
#define AIR_TREE_MODEL_H

// ======================================================
// Modelo exportado desde Python
// Proyecto 2 - Clasificacion de aire con MQ-2
// Modelo: Arbol de decision
// ======================================================

String predictAirQuality(int mq2_raw) {

  if (mq2_raw <= 3700) {
    if (mq2_raw <= 1194) {
      return "aire_limpio";
    } else {
      return "zona_intermedia";
    }
  } else {
    return "alta_concentracion";
  }

}

#endif
