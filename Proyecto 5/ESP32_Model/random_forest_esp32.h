#ifndef RANDOM_FOREST_ESP32_H
#define RANDOM_FOREST_ESP32_H

#include <Arduino.h>

// ======================================================
// RANDOM FOREST EXPORTADO PARA ESP32
// Laboratorio 5 - Sistema ambiental inteligente
// ======================================================

String tree_0(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (mq2_pct <= 62.429998) {
        if (temp_c <= 31.850000) {
            if (ldr_pct <= 51.000000) {
                return "OSCURO";
            } else {
                return "NORMAL";
            }
        } else {
            return "CALUROSO";
        }
    } else {
        if (temp_c <= 35.850000) {
            if (ldr_pct <= 80.695000) {
                return "CONTAMINADO";
            } else {
                return "NORMAL";
            }
        } else {
            return "ALERTA";
        }
    }
}

String tree_1(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (mq2_pct <= 71.049999) {
        if (ldr_pct <= 51.000000) {
            if (temp_c <= 31.850000) {
                return "OSCURO";
            } else {
                return "CALUROSO";
            }
        } else {
            return "NORMAL";
        }
    } else {
        if (mq2_pct <= 84.899998) {
            if (humidity <= 45.500000) {
                if (temp_c <= 35.850000) {
                    return "CONTAMINADO";
                } else {
                    return "ALERTA";
                }
            } else {
                return "ALERTA";
            }
        } else {
            return "CONTAMINADO";
        }
    }
}

String tree_2(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (temp_c <= 22.750000) {
        return "NORMAL";
    } else {
        if (mq2_pct <= 62.429998) {
            if (mq2_pct <= 24.929999) {
                if (temp_c <= 31.850000) {
                    return "OSCURO";
                } else {
                    return "CALUROSO";
                }
            } else {
                return "CALUROSO";
            }
        } else {
            if (temp_c <= 35.750000) {
                return "CONTAMINADO";
            } else {
                return "ALERTA";
            }
        }
    }
}

String tree_3(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (ldr_pct <= 80.695000) {
        if (humidity <= 47.750000) {
            if (humidity <= 43.750000) {
                return "ALERTA";
            } else {
                if (mq2_pct <= 62.429998) {
                    if (temp_c <= 31.850000) {
                        return "OSCURO";
                    } else {
                        return "CALUROSO";
                    }
                } else {
                    if (temp_c <= 35.800001) {
                        return "CONTAMINADO";
                    } else {
                        return "ALERTA";
                    }
                }
            }
        } else {
            return "ALERTA";
        }
    } else {
        return "NORMAL";
    }
}

String tree_4(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (mq2_pct <= 71.049999) {
        if (ldr_pct <= 51.000000) {
            if (mq2_pct <= 24.929999) {
                if (temp_c <= 31.850000) {
                    return "OSCURO";
                } else {
                    return "CALUROSO";
                }
            } else {
                return "CALUROSO";
            }
        } else {
            return "NORMAL";
        }
    } else {
        if (mq2_pct <= 84.899998) {
            if (temp_c <= 35.850000) {
                return "CONTAMINADO";
            } else {
                return "ALERTA";
            }
        } else {
            return "CONTAMINADO";
        }
    }
}

String tree_5(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (ldr_pct <= 80.695000) {
        if (temp_c <= 36.300001) {
            if (temp_c <= 31.850000) {
                if (mq2_pct <= 54.749999) {
                    return "OSCURO";
                } else {
                    return "CONTAMINADO";
                }
            } else {
                if (mq2_pct <= 71.049999) {
                    return "CALUROSO";
                } else {
                    return "CONTAMINADO";
                }
            }
        } else {
            if (mq2_pct <= 51.049998) {
                return "CALUROSO";
            } else {
                return "ALERTA";
            }
        }
    } else {
        return "NORMAL";
    }
}

String tree_6(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (temp_c <= 22.750000) {
        return "NORMAL";
    } else {
        if (temp_c <= 36.300001) {
            if (mq2_pct <= 71.049999) {
                if (temp_c <= 31.850000) {
                    return "OSCURO";
                } else {
                    return "CALUROSO";
                }
            } else {
                return "CONTAMINADO";
            }
        } else {
            if (temp_c <= 37.850000) {
                return "ALERTA";
            } else {
                return "CALUROSO";
            }
        }
    }
}

String tree_7(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (temp_c <= 22.750000) {
        return "NORMAL";
    } else {
        if (mq2_pct <= 62.429998) {
            if (temp_c <= 32.199999) {
                return "OSCURO";
            } else {
                return "CALUROSO";
            }
        } else {
            if (humidity <= 45.500000) {
                if (humidity <= 44.250000) {
                    return "ALERTA";
                } else {
                    return "CONTAMINADO";
                }
            } else {
                return "ALERTA";
            }
        }
    }
}

String tree_8(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (humidity <= 45.500000) {
        if (humidity <= 44.250000) {
            return "ALERTA";
        } else {
            if (mq2_pct <= 71.049999) {
                if (mq2_pct <= 24.929999) {
                    if (temp_c <= 32.199999) {
                        return "OSCURO";
                    } else {
                        return "CALUROSO";
                    }
                } else {
                    return "CALUROSO";
                }
            } else {
                if (temp_c <= 35.700001) {
                    return "CONTAMINADO";
                } else {
                    return "ALERTA";
                }
            }
        }
    } else {
        if (ldr_pct <= 51.000000) {
            return "ALERTA";
        } else {
            return "NORMAL";
        }
    }
}

String tree_9(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (mq2_pct <= 62.429998) {
        if (humidity <= 58.750000) {
            if (temp_c <= 32.199999) {
                return "OSCURO";
            } else {
                return "CALUROSO";
            }
        } else {
            return "NORMAL";
        }
    } else {
        if (temp_c <= 35.800001) {
            if (temp_c <= 22.750000) {
                return "NORMAL";
            } else {
                return "CONTAMINADO";
            }
        } else {
            return "ALERTA";
        }
    }
}

String tree_10(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (temp_c <= 36.350000) {
        if (mq2_pct <= 62.429998) {
            if (humidity <= 58.750000) {
                if (temp_c <= 31.850000) {
                    return "OSCURO";
                } else {
                    return "CALUROSO";
                }
            } else {
                return "NORMAL";
            }
        } else {
            if (temp_c <= 22.750000) {
                return "NORMAL";
            } else {
                return "CONTAMINADO";
            }
        }
    } else {
        if (humidity <= 45.500000) {
            if (mq2_pct <= 51.049998) {
                return "CALUROSO";
            } else {
                return "ALERTA";
            }
        } else {
            return "ALERTA";
        }
    }
}

String tree_11(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (mq2_pct <= 62.429998) {
        if (temp_c <= 31.850000) {
            if (temp_c <= 22.750000) {
                return "NORMAL";
            } else {
                return "OSCURO";
            }
        } else {
            return "CALUROSO";
        }
    } else {
        if (temp_c <= 35.850000) {
            if (temp_c <= 22.750000) {
                return "NORMAL";
            } else {
                return "CONTAMINADO";
            }
        } else {
            return "ALERTA";
        }
    }
}

String tree_12(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (ldr_pct <= 80.695000) {
        if (humidity <= 45.500000) {
            if (temp_c <= 31.850000) {
                if (mq2_pct <= 54.749999) {
                    return "OSCURO";
                } else {
                    return "CONTAMINADO";
                }
            } else {
                if (humidity <= 44.250000) {
                    return "ALERTA";
                } else {
                    if (mq2_pct <= 71.049999) {
                        return "CALUROSO";
                    } else {
                        if (temp_c <= 35.800001) {
                            return "CONTAMINADO";
                        } else {
                            return "ALERTA";
                        }
                    }
                }
            }
        } else {
            return "ALERTA";
        }
    } else {
        return "NORMAL";
    }
}

String tree_13(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (temp_c <= 22.750000) {
        return "NORMAL";
    } else {
        if (humidity <= 45.500000) {
            if (ldr_pct <= 33.625000) {
                if (mq2_pct <= 71.049999) {
                    if (temp_c <= 31.850000) {
                        return "OSCURO";
                    } else {
                        return "CALUROSO";
                    }
                } else {
                    if (temp_c <= 35.850000) {
                        return "CONTAMINADO";
                    } else {
                        return "ALERTA";
                    }
                }
            } else {
                return "CONTAMINADO";
            }
        } else {
            return "ALERTA";
        }
    }
}

String tree_14(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (ldr_pct <= 80.695000) {
        if (humidity <= 45.500000) {
            if (mq2_pct <= 62.429998) {
                if (mq2_pct <= 24.929999) {
                    if (temp_c <= 31.850000) {
                        return "OSCURO";
                    } else {
                        return "CALUROSO";
                    }
                } else {
                    return "CALUROSO";
                }
            } else {
                if (humidity <= 44.250000) {
                    return "ALERTA";
                } else {
                    if (temp_c <= 35.850000) {
                        return "CONTAMINADO";
                    } else {
                        return "ALERTA";
                    }
                }
            }
        } else {
            return "ALERTA";
        }
    } else {
        return "NORMAL";
    }
}

String tree_15(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (ldr_pct <= 80.695000) {
        if (mq2_pct <= 71.049999) {
            if (temp_c <= 31.850000) {
                return "OSCURO";
            } else {
                return "CALUROSO";
            }
        } else {
            if (humidity <= 45.500000) {
                if (humidity <= 44.250000) {
                    return "ALERTA";
                } else {
                    return "CONTAMINADO";
                }
            } else {
                return "ALERTA";
            }
        }
    } else {
        return "NORMAL";
    }
}

String tree_16(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (humidity <= 45.500000) {
        if (mq2_pct <= 62.429998) {
            if (temp_c <= 31.850000) {
                return "OSCURO";
            } else {
                return "CALUROSO";
            }
        } else {
            if (temp_c <= 35.850000) {
                return "CONTAMINADO";
            } else {
                return "ALERTA";
            }
        }
    } else {
        if (ldr_pct <= 51.000000) {
            return "ALERTA";
        } else {
            return "NORMAL";
        }
    }
}

String tree_17(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (ldr_pct <= 80.695000) {
        if (mq2_pct <= 62.429998) {
            if (mq2_pct <= 24.929999) {
                if (temp_c <= 32.199999) {
                    return "OSCURO";
                } else {
                    return "CALUROSO";
                }
            } else {
                return "CALUROSO";
            }
        } else {
            if (temp_c <= 35.700001) {
                return "CONTAMINADO";
            } else {
                return "ALERTA";
            }
        }
    } else {
        return "NORMAL";
    }
}

String tree_18(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (ldr_pct <= 80.695000) {
        if (temp_c <= 36.350000) {
            if (temp_c <= 32.199999) {
                if (mq2_pct <= 54.749999) {
                    return "OSCURO";
                } else {
                    return "CONTAMINADO";
                }
            } else {
                if (temp_c <= 34.650000) {
                    return "CALUROSO";
                } else {
                    if (temp_c <= 35.000000) {
                        if (mq2_pct <= 71.049999) {
                            return "CALUROSO";
                        } else {
                            return "CONTAMINADO";
                        }
                    } else {
                        return "CALUROSO";
                    }
                }
            }
        } else {
            if (temp_c <= 37.850000) {
                return "ALERTA";
            } else {
                return "CALUROSO";
            }
        }
    } else {
        return "NORMAL";
    }
}

String tree_19(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (temp_c <= 22.750000) {
        return "NORMAL";
    } else {
        if (mq2_pct <= 71.049999) {
            if (temp_c <= 32.199999) {
                return "OSCURO";
            } else {
                return "CALUROSO";
            }
        } else {
            if (humidity <= 45.500000) {
                if (mq2_pct <= 84.899998) {
                    if (humidity <= 44.250000) {
                        return "ALERTA";
                    } else {
                        if (temp_c <= 35.800001) {
                            return "CONTAMINADO";
                        } else {
                            return "ALERTA";
                        }
                    }
                } else {
                    return "CONTAMINADO";
                }
            } else {
                return "ALERTA";
            }
        }
    }
}

String tree_20(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (mq2_pct <= 62.429998) {
        if (temp_c <= 31.900000) {
            if (ldr_pct <= 51.000000) {
                return "OSCURO";
            } else {
                return "NORMAL";
            }
        } else {
            return "CALUROSO";
        }
    } else {
        if (mq2_pct <= 84.899998) {
            if (humidity <= 45.500000) {
                if (humidity <= 44.250000) {
                    return "ALERTA";
                } else {
                    if (temp_c <= 35.800001) {
                        return "CONTAMINADO";
                    } else {
                        return "ALERTA";
                    }
                }
            } else {
                return "ALERTA";
            }
        } else {
            return "CONTAMINADO";
        }
    }
}

String tree_21(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (ldr_pct <= 80.695000) {
        if (mq2_pct <= 62.429998) {
            if (mq2_pct <= 24.929999) {
                if (temp_c <= 31.550001) {
                    return "OSCURO";
                } else {
                    return "CALUROSO";
                }
            } else {
                return "CALUROSO";
            }
        } else {
            if (temp_c <= 35.800001) {
                return "CONTAMINADO";
            } else {
                return "ALERTA";
            }
        }
    } else {
        return "NORMAL";
    }
}

String tree_22(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (ldr_pct <= 80.695000) {
        if (humidity <= 45.500000) {
            if (temp_c <= 32.199999) {
                if (ldr_pct <= 33.625000) {
                    if (mq2_pct <= 54.749999) {
                        return "OSCURO";
                    } else {
                        return "CONTAMINADO";
                    }
                } else {
                    return "CONTAMINADO";
                }
            } else {
                if (mq2_pct <= 71.049999) {
                    return "CALUROSO";
                } else {
                    if (humidity <= 44.250000) {
                        return "ALERTA";
                    } else {
                        if (temp_c <= 35.700001) {
                            return "CONTAMINADO";
                        } else {
                            return "ALERTA";
                        }
                    }
                }
            }
        } else {
            return "ALERTA";
        }
    } else {
        return "NORMAL";
    }
}

String tree_23(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (humidity <= 47.750000) {
        if (temp_c <= 32.199999) {
            if (mq2_pct <= 54.749999) {
                return "OSCURO";
            } else {
                return "CONTAMINADO";
            }
        } else {
            if (temp_c <= 34.650000) {
                return "CALUROSO";
            } else {
                if (temp_c <= 34.900000) {
                    if (mq2_pct <= 71.049999) {
                        return "CALUROSO";
                    } else {
                        return "CONTAMINADO";
                    }
                } else {
                    if (humidity <= 44.250000) {
                        return "ALERTA";
                    } else {
                        if (temp_c <= 36.300001) {
                            return "CALUROSO";
                        } else {
                            if (mq2_pct <= 51.049998) {
                                return "CALUROSO";
                            } else {
                                return "ALERTA";
                            }
                        }
                    }
                }
            }
        }
    } else {
        if (ldr_pct <= 51.000000) {
            return "ALERTA";
        } else {
            return "NORMAL";
        }
    }
}

String tree_24(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (humidity <= 47.750000) {
        if (mq2_pct <= 71.049999) {
            if (temp_c <= 31.850000) {
                return "OSCURO";
            } else {
                return "CALUROSO";
            }
        } else {
            if (temp_c <= 35.850000) {
                return "CONTAMINADO";
            } else {
                return "ALERTA";
            }
        }
    } else {
        if (temp_c <= 29.099999) {
            return "NORMAL";
        } else {
            return "ALERTA";
        }
    }
}

String tree_25(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (temp_c <= 22.750000) {
        return "NORMAL";
    } else {
        if (temp_c <= 31.850000) {
            if (ldr_pct <= 33.625000) {
                if (temp_c <= 27.400001) {
                    if (mq2_pct <= 54.749999) {
                        return "OSCURO";
                    } else {
                        return "CONTAMINADO";
                    }
                } else {
                    return "OSCURO";
                }
            } else {
                return "CONTAMINADO";
            }
        } else {
            if (mq2_pct <= 62.429998) {
                return "CALUROSO";
            } else {
                if (temp_c <= 35.700001) {
                    return "CONTAMINADO";
                } else {
                    return "ALERTA";
                }
            }
        }
    }
}

String tree_26(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (humidity <= 45.500000) {
        if (temp_c <= 31.850000) {
            if (ldr_pct <= 33.625000) {
                if (mq2_pct <= 54.749999) {
                    return "OSCURO";
                } else {
                    return "CONTAMINADO";
                }
            } else {
                return "CONTAMINADO";
            }
        } else {
            if (mq2_pct <= 62.429998) {
                return "CALUROSO";
            } else {
                if (temp_c <= 35.750000) {
                    return "CONTAMINADO";
                } else {
                    return "ALERTA";
                }
            }
        }
    } else {
        if (temp_c <= 29.099999) {
            return "NORMAL";
        } else {
            return "ALERTA";
        }
    }
}

String tree_27(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (ldr_pct <= 80.695000) {
        if (humidity <= 45.500000) {
            if (mq2_pct <= 71.049999) {
                if (temp_c <= 31.850000) {
                    return "OSCURO";
                } else {
                    return "CALUROSO";
                }
            } else {
                if (temp_c <= 35.850000) {
                    return "CONTAMINADO";
                } else {
                    return "ALERTA";
                }
            }
        } else {
            return "ALERTA";
        }
    } else {
        return "NORMAL";
    }
}

String tree_28(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (temp_c <= 22.750000) {
        return "NORMAL";
    } else {
        if (mq2_pct <= 71.049999) {
            if (temp_c <= 32.199999) {
                return "OSCURO";
            } else {
                return "CALUROSO";
            }
        } else {
            if (temp_c <= 35.850000) {
                return "CONTAMINADO";
            } else {
                return "ALERTA";
            }
        }
    }
}

String tree_29(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (temp_c <= 22.750000) {
        return "NORMAL";
    } else {
        if (temp_c <= 31.850000) {
            if (temp_c <= 27.400001) {
                if (ldr_pct <= 33.625000) {
                    if (mq2_pct <= 54.749999) {
                        return "OSCURO";
                    } else {
                        return "CONTAMINADO";
                    }
                } else {
                    return "CONTAMINADO";
                }
            } else {
                return "OSCURO";
            }
        } else {
            if (humidity <= 45.500000) {
                if (temp_c <= 34.100000) {
                    return "CALUROSO";
                } else {
                    if (mq2_pct <= 62.429998) {
                        return "CALUROSO";
                    } else {
                        if (temp_c <= 35.800001) {
                            return "CONTAMINADO";
                        } else {
                            return "ALERTA";
                        }
                    }
                }
            } else {
                return "ALERTA";
            }
        }
    }
}

String tree_30(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (mq2_pct <= 62.429998) {
        if (temp_c <= 32.199999) {
            if (temp_c <= 22.750000) {
                return "NORMAL";
            } else {
                return "OSCURO";
            }
        } else {
            return "CALUROSO";
        }
    } else {
        if (temp_c <= 35.800001) {
            if (ldr_pct <= 80.695000) {
                return "CONTAMINADO";
            } else {
                return "NORMAL";
            }
        } else {
            return "ALERTA";
        }
    }
}

String tree_31(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (mq2_pct <= 71.049999) {
        if (humidity <= 58.750000) {
            if (temp_c <= 31.850000) {
                return "OSCURO";
            } else {
                return "CALUROSO";
            }
        } else {
            return "NORMAL";
        }
    } else {
        if (humidity <= 47.750000) {
            if (humidity <= 44.250000) {
                return "ALERTA";
            } else {
                if (mq2_pct <= 84.899998) {
                    if (temp_c <= 35.850000) {
                        return "CONTAMINADO";
                    } else {
                        return "ALERTA";
                    }
                } else {
                    return "CONTAMINADO";
                }
            }
        } else {
            return "ALERTA";
        }
    }
}

String tree_32(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (mq2_pct <= 71.049999) {
        if (temp_c <= 32.199999) {
            if (humidity <= 58.750000) {
                return "OSCURO";
            } else {
                return "NORMAL";
            }
        } else {
            return "CALUROSO";
        }
    } else {
        if (humidity <= 45.500000) {
            if (mq2_pct <= 84.899998) {
                if (temp_c <= 35.800001) {
                    return "CONTAMINADO";
                } else {
                    return "ALERTA";
                }
            } else {
                return "CONTAMINADO";
            }
        } else {
            if (ldr_pct <= 51.000000) {
                return "ALERTA";
            } else {
                return "NORMAL";
            }
        }
    }
}

String tree_33(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (temp_c <= 22.750000) {
        return "NORMAL";
    } else {
        if (mq2_pct <= 62.429998) {
            if (temp_c <= 32.199999) {
                return "OSCURO";
            } else {
                return "CALUROSO";
            }
        } else {
            if (temp_c <= 35.800001) {
                return "CONTAMINADO";
            } else {
                return "ALERTA";
            }
        }
    }
}

String tree_34(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (humidity <= 47.750000) {
        if (mq2_pct <= 71.049999) {
            if (mq2_pct <= 24.929999) {
                if (temp_c <= 31.550001) {
                    return "OSCURO";
                } else {
                    return "CALUROSO";
                }
            } else {
                return "CALUROSO";
            }
        } else {
            if (humidity <= 44.250000) {
                return "ALERTA";
            } else {
                if (temp_c <= 35.800001) {
                    return "CONTAMINADO";
                } else {
                    return "ALERTA";
                }
            }
        }
    } else {
        if (mq2_pct <= 53.039998) {
            return "NORMAL";
        } else {
            return "ALERTA";
        }
    }
}

String tree_35(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (ldr_pct <= 80.695000) {
        if (humidity <= 45.500000) {
            if (mq2_pct <= 62.429998) {
                if (mq2_pct <= 24.929999) {
                    if (temp_c <= 32.199999) {
                        return "OSCURO";
                    } else {
                        return "CALUROSO";
                    }
                } else {
                    return "CALUROSO";
                }
            } else {
                if (mq2_pct <= 84.899998) {
                    if (humidity <= 44.250000) {
                        return "ALERTA";
                    } else {
                        return "CONTAMINADO";
                    }
                } else {
                    return "CONTAMINADO";
                }
            }
        } else {
            return "ALERTA";
        }
    } else {
        return "NORMAL";
    }
}

String tree_36(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (temp_c <= 22.750000) {
        return "NORMAL";
    } else {
        if (mq2_pct <= 71.049999) {
            if (temp_c <= 31.850000) {
                return "OSCURO";
            } else {
                return "CALUROSO";
            }
        } else {
            if (humidity <= 45.500000) {
                if (humidity <= 44.250000) {
                    return "ALERTA";
                } else {
                    if (mq2_pct <= 84.899998) {
                        if (temp_c <= 35.800001) {
                            return "CONTAMINADO";
                        } else {
                            return "ALERTA";
                        }
                    } else {
                        return "CONTAMINADO";
                    }
                }
            } else {
                return "ALERTA";
            }
        }
    }
}

String tree_37(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (temp_c <= 22.750000) {
        return "NORMAL";
    } else {
        if (humidity <= 45.500000) {
            if (mq2_pct <= 62.429998) {
                if (mq2_pct <= 24.929999) {
                    if (temp_c <= 31.550001) {
                        return "OSCURO";
                    } else {
                        return "CALUROSO";
                    }
                } else {
                    return "CALUROSO";
                }
            } else {
                if (humidity <= 44.250000) {
                    return "ALERTA";
                } else {
                    if (temp_c <= 35.800001) {
                        return "CONTAMINADO";
                    } else {
                        return "ALERTA";
                    }
                }
            }
        } else {
            return "ALERTA";
        }
    }
}

String tree_38(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (mq2_pct <= 71.049999) {
        if (temp_c <= 32.199999) {
            if (humidity <= 58.750000) {
                return "OSCURO";
            } else {
                return "NORMAL";
            }
        } else {
            return "CALUROSO";
        }
    } else {
        if (humidity <= 45.500000) {
            if (humidity <= 44.250000) {
                return "ALERTA";
            } else {
                if (temp_c <= 35.800001) {
                    return "CONTAMINADO";
                } else {
                    return "ALERTA";
                }
            }
        } else {
            return "ALERTA";
        }
    }
}

String tree_39(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (temp_c <= 22.750000) {
        return "NORMAL";
    } else {
        if (temp_c <= 31.850000) {
            if (mq2_pct <= 54.749999) {
                return "OSCURO";
            } else {
                return "CONTAMINADO";
            }
        } else {
            if (temp_c <= 36.350000) {
                if (temp_c <= 34.650000) {
                    return "CALUROSO";
                } else {
                    if (mq2_pct <= 71.049999) {
                        return "CALUROSO";
                    } else {
                        return "CONTAMINADO";
                    }
                }
            } else {
                if (mq2_pct <= 51.049998) {
                    return "CALUROSO";
                } else {
                    return "ALERTA";
                }
            }
        }
    }
}

String tree_40(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (ldr_pct <= 80.695000) {
        if (humidity <= 45.500000) {
            if (temp_c <= 32.199999) {
                if (temp_c <= 27.400001) {
                    if (ldr_pct <= 33.625000) {
                        if (mq2_pct <= 54.749999) {
                            return "OSCURO";
                        } else {
                            return "CONTAMINADO";
                        }
                    } else {
                        return "CONTAMINADO";
                    }
                } else {
                    return "OSCURO";
                }
            } else {
                if (humidity <= 44.250000) {
                    return "ALERTA";
                } else {
                    if (mq2_pct <= 62.429998) {
                        return "CALUROSO";
                    } else {
                        if (temp_c <= 35.700001) {
                            return "CONTAMINADO";
                        } else {
                            return "ALERTA";
                        }
                    }
                }
            }
        } else {
            return "ALERTA";
        }
    } else {
        return "NORMAL";
    }
}

String tree_41(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (temp_c <= 22.750000) {
        return "NORMAL";
    } else {
        if (temp_c <= 36.350000) {
            if (temp_c <= 31.550001) {
                if (mq2_pct <= 54.749999) {
                    return "OSCURO";
                } else {
                    return "CONTAMINADO";
                }
            } else {
                if (mq2_pct <= 71.049999) {
                    return "CALUROSO";
                } else {
                    return "CONTAMINADO";
                }
            }
        } else {
            if (mq2_pct <= 51.049998) {
                return "CALUROSO";
            } else {
                return "ALERTA";
            }
        }
    }
}

String tree_42(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (temp_c <= 22.750000) {
        return "NORMAL";
    } else {
        if (mq2_pct <= 71.049999) {
            if (mq2_pct <= 24.929999) {
                if (temp_c <= 32.199999) {
                    return "OSCURO";
                } else {
                    return "CALUROSO";
                }
            } else {
                return "CALUROSO";
            }
        } else {
            if (mq2_pct <= 84.899998) {
                if (temp_c <= 35.850000) {
                    return "CONTAMINADO";
                } else {
                    return "ALERTA";
                }
            } else {
                return "CONTAMINADO";
            }
        }
    }
}

String tree_43(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (temp_c <= 22.750000) {
        return "NORMAL";
    } else {
        if (humidity <= 45.500000) {
            if (temp_c <= 31.850000) {
                if (ldr_pct <= 33.625000) {
                    if (mq2_pct <= 54.749999) {
                        return "OSCURO";
                    } else {
                        return "CONTAMINADO";
                    }
                } else {
                    return "CONTAMINADO";
                }
            } else {
                if (mq2_pct <= 62.429998) {
                    return "CALUROSO";
                } else {
                    if (temp_c <= 35.750000) {
                        return "CONTAMINADO";
                    } else {
                        return "ALERTA";
                    }
                }
            }
        } else {
            return "ALERTA";
        }
    }
}

String tree_44(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (temp_c <= 31.850000) {
        if (temp_c <= 22.750000) {
            return "NORMAL";
        } else {
            if (ldr_pct <= 33.625000) {
                if (mq2_pct <= 54.749999) {
                    return "OSCURO";
                } else {
                    return "CONTAMINADO";
                }
            } else {
                return "CONTAMINADO";
            }
        }
    } else {
        if (temp_c <= 36.300001) {
            if (temp_c <= 34.650000) {
                return "CALUROSO";
            } else {
                if (mq2_pct <= 71.049999) {
                    return "CALUROSO";
                } else {
                    return "CONTAMINADO";
                }
            }
        } else {
            if (temp_c <= 37.850000) {
                return "ALERTA";
            } else {
                return "CALUROSO";
            }
        }
    }
}

String tree_45(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (mq2_pct <= 71.049999) {
        if (temp_c <= 31.550001) {
            if (ldr_pct <= 51.000000) {
                return "OSCURO";
            } else {
                return "NORMAL";
            }
        } else {
            return "CALUROSO";
        }
    } else {
        if (mq2_pct <= 84.899998) {
            if (humidity <= 45.500000) {
                if (temp_c <= 35.700001) {
                    return "CONTAMINADO";
                } else {
                    return "ALERTA";
                }
            } else {
                return "ALERTA";
            }
        } else {
            return "CONTAMINADO";
        }
    }
}

String tree_46(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (ldr_pct <= 80.695000) {
        if (humidity <= 45.500000) {
            if (humidity <= 44.250000) {
                return "ALERTA";
            } else {
                if (ldr_pct <= 33.625000) {
                    if (temp_c <= 31.850000) {
                        if (mq2_pct <= 54.749999) {
                            return "OSCURO";
                        } else {
                            return "CONTAMINADO";
                        }
                    } else {
                        if (mq2_pct <= 71.049999) {
                            return "CALUROSO";
                        } else {
                            if (temp_c <= 35.700001) {
                                return "CONTAMINADO";
                            } else {
                                return "ALERTA";
                            }
                        }
                    }
                } else {
                    return "CONTAMINADO";
                }
            }
        } else {
            return "ALERTA";
        }
    } else {
        return "NORMAL";
    }
}

String tree_47(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (temp_c <= 36.350000) {
        if (mq2_pct <= 71.049999) {
            if (temp_c <= 22.750000) {
                return "NORMAL";
            } else {
                if (temp_c <= 31.850000) {
                    return "OSCURO";
                } else {
                    return "CALUROSO";
                }
            }
        } else {
            if (humidity <= 58.750000) {
                return "CONTAMINADO";
            } else {
                return "NORMAL";
            }
        }
    } else {
        if (mq2_pct <= 51.049998) {
            return "CALUROSO";
        } else {
            return "ALERTA";
        }
    }
}

String tree_48(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (temp_c <= 22.750000) {
        return "NORMAL";
    } else {
        if (humidity <= 45.500000) {
            if (humidity <= 44.250000) {
                return "ALERTA";
            } else {
                if (mq2_pct <= 71.049999) {
                    if (temp_c <= 31.850000) {
                        return "OSCURO";
                    } else {
                        return "CALUROSO";
                    }
                } else {
                    if (ldr_pct <= 33.625000) {
                        if (temp_c <= 35.800001) {
                            return "CONTAMINADO";
                        } else {
                            return "ALERTA";
                        }
                    } else {
                        return "CONTAMINADO";
                    }
                }
            }
        } else {
            return "ALERTA";
        }
    }
}

String tree_49(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (temp_c <= 22.750000) {
        return "NORMAL";
    } else {
        if (mq2_pct <= 71.049999) {
            if (temp_c <= 31.850000) {
                return "OSCURO";
            } else {
                return "CALUROSO";
            }
        } else {
            if (humidity <= 45.500000) {
                if (temp_c <= 35.850000) {
                    return "CONTAMINADO";
                } else {
                    return "ALERTA";
                }
            } else {
                return "ALERTA";
            }
        }
    }
}

String tree_50(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (mq2_pct <= 62.429998) {
        if (ldr_pct <= 51.000000) {
            if (temp_c <= 31.550001) {
                return "OSCURO";
            } else {
                return "CALUROSO";
            }
        } else {
            return "NORMAL";
        }
    } else {
        if (humidity <= 45.500000) {
            if (temp_c <= 35.800001) {
                return "CONTAMINADO";
            } else {
                return "ALERTA";
            }
        } else {
            if (temp_c <= 29.099999) {
                return "NORMAL";
            } else {
                return "ALERTA";
            }
        }
    }
}

String tree_51(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (temp_c <= 22.750000) {
        return "NORMAL";
    } else {
        if (humidity <= 47.750000) {
            if (temp_c <= 32.199999) {
                if (mq2_pct <= 54.749999) {
                    return "OSCURO";
                } else {
                    return "CONTAMINADO";
                }
            } else {
                if (temp_c <= 34.650000) {
                    return "CALUROSO";
                } else {
                    if (mq2_pct <= 71.049999) {
                        return "CALUROSO";
                    } else {
                        if (temp_c <= 35.700001) {
                            return "CONTAMINADO";
                        } else {
                            return "ALERTA";
                        }
                    }
                }
            }
        } else {
            return "ALERTA";
        }
    }
}

String tree_52(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (ldr_pct <= 80.695000) {
        if (mq2_pct <= 71.049999) {
            if (temp_c <= 32.199999) {
                return "OSCURO";
            } else {
                return "CALUROSO";
            }
        } else {
            if (temp_c <= 35.800001) {
                return "CONTAMINADO";
            } else {
                return "ALERTA";
            }
        }
    } else {
        return "NORMAL";
    }
}

String tree_53(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (mq2_pct <= 62.429998) {
        if (humidity <= 58.750000) {
            if (mq2_pct <= 24.929999) {
                if (temp_c <= 31.550001) {
                    return "OSCURO";
                } else {
                    return "CALUROSO";
                }
            } else {
                return "CALUROSO";
            }
        } else {
            return "NORMAL";
        }
    } else {
        if (temp_c <= 35.850000) {
            return "CONTAMINADO";
        } else {
            return "ALERTA";
        }
    }
}

String tree_54(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (temp_c <= 22.750000) {
        return "NORMAL";
    } else {
        if (mq2_pct <= 71.049999) {
            if (temp_c <= 31.850000) {
                return "OSCURO";
            } else {
                return "CALUROSO";
            }
        } else {
            if (mq2_pct <= 84.899998) {
                if (humidity <= 45.500000) {
                    if (humidity <= 44.250000) {
                        return "ALERTA";
                    } else {
                        if (temp_c <= 35.700001) {
                            return "CONTAMINADO";
                        } else {
                            return "ALERTA";
                        }
                    }
                } else {
                    return "ALERTA";
                }
            } else {
                return "CONTAMINADO";
            }
        }
    }
}

String tree_55(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (mq2_pct <= 62.429998) {
        if (temp_c <= 31.850000) {
            if (humidity <= 58.750000) {
                return "OSCURO";
            } else {
                return "NORMAL";
            }
        } else {
            return "CALUROSO";
        }
    } else {
        if (humidity <= 45.500000) {
            if (humidity <= 44.250000) {
                return "ALERTA";
            } else {
                if (temp_c <= 35.700001) {
                    return "CONTAMINADO";
                } else {
                    return "ALERTA";
                }
            }
        } else {
            if (temp_c <= 29.099999) {
                return "NORMAL";
            } else {
                return "ALERTA";
            }
        }
    }
}

String tree_56(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (temp_c <= 22.750000) {
        return "NORMAL";
    } else {
        if (temp_c <= 31.850000) {
            if (ldr_pct <= 33.625000) {
                if (temp_c <= 27.400001) {
                    if (mq2_pct <= 54.749999) {
                        return "OSCURO";
                    } else {
                        return "CONTAMINADO";
                    }
                } else {
                    return "OSCURO";
                }
            } else {
                return "CONTAMINADO";
            }
        } else {
            if (temp_c <= 36.300001) {
                if (mq2_pct <= 71.049999) {
                    return "CALUROSO";
                } else {
                    return "CONTAMINADO";
                }
            } else {
                if (temp_c <= 37.850000) {
                    return "ALERTA";
                } else {
                    return "CALUROSO";
                }
            }
        }
    }
}

String tree_57(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (humidity <= 45.500000) {
        if (mq2_pct <= 71.049999) {
            if (temp_c <= 31.900000) {
                return "OSCURO";
            } else {
                return "CALUROSO";
            }
        } else {
            if (temp_c <= 35.750000) {
                return "CONTAMINADO";
            } else {
                return "ALERTA";
            }
        }
    } else {
        if (mq2_pct <= 53.039998) {
            return "NORMAL";
        } else {
            if (temp_c <= 29.099999) {
                return "NORMAL";
            } else {
                return "ALERTA";
            }
        }
    }
}

String tree_58(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (humidity <= 45.500000) {
        if (mq2_pct <= 71.049999) {
            if (temp_c <= 32.199999) {
                return "OSCURO";
            } else {
                return "CALUROSO";
            }
        } else {
            if (humidity <= 44.250000) {
                return "ALERTA";
            } else {
                if (mq2_pct <= 84.899998) {
                    if (temp_c <= 35.800001) {
                        return "CONTAMINADO";
                    } else {
                        return "ALERTA";
                    }
                } else {
                    return "CONTAMINADO";
                }
            }
        }
    } else {
        if (temp_c <= 29.099999) {
            return "NORMAL";
        } else {
            return "ALERTA";
        }
    }
}

String tree_59(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (mq2_pct <= 71.049999) {
        if (ldr_pct <= 51.000000) {
            if (mq2_pct <= 24.929999) {
                if (temp_c <= 32.199999) {
                    return "OSCURO";
                } else {
                    return "CALUROSO";
                }
            } else {
                return "CALUROSO";
            }
        } else {
            return "NORMAL";
        }
    } else {
        if (temp_c <= 35.800001) {
            if (humidity <= 58.750000) {
                return "CONTAMINADO";
            } else {
                return "NORMAL";
            }
        } else {
            return "ALERTA";
        }
    }
}

String tree_60(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (ldr_pct <= 80.695000) {
        if (humidity <= 45.500000) {
            if (humidity <= 44.250000) {
                return "ALERTA";
            } else {
                if (ldr_pct <= 33.625000) {
                    if (mq2_pct <= 62.429998) {
                        if (temp_c <= 31.850000) {
                            return "OSCURO";
                        } else {
                            return "CALUROSO";
                        }
                    } else {
                        if (mq2_pct <= 84.899998) {
                            if (temp_c <= 35.800001) {
                                return "CONTAMINADO";
                            } else {
                                return "ALERTA";
                            }
                        } else {
                            return "CONTAMINADO";
                        }
                    }
                } else {
                    return "CONTAMINADO";
                }
            }
        } else {
            return "ALERTA";
        }
    } else {
        return "NORMAL";
    }
}

String tree_61(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (temp_c <= 22.750000) {
        return "NORMAL";
    } else {
        if (mq2_pct <= 71.049999) {
            if (mq2_pct <= 24.929999) {
                if (temp_c <= 31.850000) {
                    return "OSCURO";
                } else {
                    return "CALUROSO";
                }
            } else {
                return "CALUROSO";
            }
        } else {
            if (mq2_pct <= 84.899998) {
                if (temp_c <= 35.700001) {
                    return "CONTAMINADO";
                } else {
                    return "ALERTA";
                }
            } else {
                return "CONTAMINADO";
            }
        }
    }
}

String tree_62(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (mq2_pct <= 71.049999) {
        if (ldr_pct <= 51.000000) {
            if (temp_c <= 31.850000) {
                return "OSCURO";
            } else {
                return "CALUROSO";
            }
        } else {
            return "NORMAL";
        }
    } else {
        if (temp_c <= 35.800001) {
            return "CONTAMINADO";
        } else {
            return "ALERTA";
        }
    }
}

String tree_63(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (humidity <= 45.500000) {
        if (ldr_pct <= 33.625000) {
            if (temp_c <= 32.199999) {
                if (temp_c <= 27.400001) {
                    if (mq2_pct <= 54.749999) {
                        return "OSCURO";
                    } else {
                        return "CONTAMINADO";
                    }
                } else {
                    return "OSCURO";
                }
            } else {
                if (mq2_pct <= 62.429998) {
                    return "CALUROSO";
                } else {
                    if (temp_c <= 35.850000) {
                        return "CONTAMINADO";
                    } else {
                        return "ALERTA";
                    }
                }
            }
        } else {
            return "CONTAMINADO";
        }
    } else {
        if (mq2_pct <= 53.039998) {
            return "NORMAL";
        } else {
            return "ALERTA";
        }
    }
}

String tree_64(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (temp_c <= 22.750000) {
        return "NORMAL";
    } else {
        if (mq2_pct <= 71.049999) {
            if (mq2_pct <= 24.929999) {
                if (temp_c <= 31.900000) {
                    return "OSCURO";
                } else {
                    return "CALUROSO";
                }
            } else {
                return "CALUROSO";
            }
        } else {
            if (mq2_pct <= 84.899998) {
                if (humidity <= 47.750000) {
                    if (temp_c <= 35.800001) {
                        return "CONTAMINADO";
                    } else {
                        return "ALERTA";
                    }
                } else {
                    return "ALERTA";
                }
            } else {
                return "CONTAMINADO";
            }
        }
    }
}

String tree_65(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (ldr_pct <= 51.000000) {
        if (mq2_pct <= 62.429998) {
            if (temp_c <= 31.850000) {
                return "OSCURO";
            } else {
                return "CALUROSO";
            }
        } else {
            if (temp_c <= 35.800001) {
                return "CONTAMINADO";
            } else {
                return "ALERTA";
            }
        }
    } else {
        return "NORMAL";
    }
}

String tree_66(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (mq2_pct <= 62.429998) {
        if (temp_c <= 31.850000) {
            if (temp_c <= 22.750000) {
                return "NORMAL";
            } else {
                return "OSCURO";
            }
        } else {
            return "CALUROSO";
        }
    } else {
        if (humidity <= 45.500000) {
            if (temp_c <= 35.750000) {
                return "CONTAMINADO";
            } else {
                return "ALERTA";
            }
        } else {
            if (temp_c <= 29.099999) {
                return "NORMAL";
            } else {
                return "ALERTA";
            }
        }
    }
}

String tree_67(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (ldr_pct <= 80.695000) {
        if (humidity <= 45.500000) {
            if (temp_c <= 31.850000) {
                if (mq2_pct <= 54.749999) {
                    return "OSCURO";
                } else {
                    return "CONTAMINADO";
                }
            } else {
                if (mq2_pct <= 71.049999) {
                    return "CALUROSO";
                } else {
                    if (humidity <= 44.250000) {
                        return "ALERTA";
                    } else {
                        if (temp_c <= 35.700001) {
                            return "CONTAMINADO";
                        } else {
                            return "ALERTA";
                        }
                    }
                }
            }
        } else {
            return "ALERTA";
        }
    } else {
        return "NORMAL";
    }
}

String tree_68(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (temp_c <= 22.750000) {
        return "NORMAL";
    } else {
        if (mq2_pct <= 71.049999) {
            if (temp_c <= 31.850000) {
                return "OSCURO";
            } else {
                return "CALUROSO";
            }
        } else {
            if (humidity <= 47.750000) {
                if (humidity <= 43.750000) {
                    return "ALERTA";
                } else {
                    if (ldr_pct <= 33.625000) {
                        if (mq2_pct <= 84.899998) {
                            if (temp_c <= 35.850000) {
                                return "CONTAMINADO";
                            } else {
                                return "ALERTA";
                            }
                        } else {
                            return "CONTAMINADO";
                        }
                    } else {
                        return "CONTAMINADO";
                    }
                }
            } else {
                return "ALERTA";
            }
        }
    }
}

String tree_69(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (humidity <= 45.500000) {
        if (temp_c <= 32.199999) {
            if (mq2_pct <= 54.749999) {
                return "OSCURO";
            } else {
                return "CONTAMINADO";
            }
        } else {
            if (temp_c <= 34.650000) {
                return "CALUROSO";
            } else {
                if (humidity <= 44.250000) {
                    return "ALERTA";
                } else {
                    if (mq2_pct <= 71.049999) {
                        return "CALUROSO";
                    } else {
                        if (temp_c <= 35.750000) {
                            return "CONTAMINADO";
                        } else {
                            return "ALERTA";
                        }
                    }
                }
            }
        }
    } else {
        if (temp_c <= 29.099999) {
            return "NORMAL";
        } else {
            return "ALERTA";
        }
    }
}

String tree_70(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (mq2_pct <= 71.049999) {
        if (temp_c <= 22.750000) {
            return "NORMAL";
        } else {
            if (temp_c <= 32.199999) {
                return "OSCURO";
            } else {
                return "CALUROSO";
            }
        }
    } else {
        if (temp_c <= 35.800001) {
            return "CONTAMINADO";
        } else {
            return "ALERTA";
        }
    }
}

String tree_71(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (ldr_pct <= 80.695000) {
        if (temp_c <= 31.850000) {
            if (ldr_pct <= 33.625000) {
                if (temp_c <= 27.400001) {
                    if (mq2_pct <= 54.749999) {
                        return "OSCURO";
                    } else {
                        return "CONTAMINADO";
                    }
                } else {
                    return "OSCURO";
                }
            } else {
                return "CONTAMINADO";
            }
        } else {
            if (humidity <= 45.500000) {
                if (humidity <= 44.250000) {
                    return "ALERTA";
                } else {
                    if (mq2_pct <= 62.429998) {
                        return "CALUROSO";
                    } else {
                        return "CONTAMINADO";
                    }
                }
            } else {
                return "ALERTA";
            }
        }
    } else {
        return "NORMAL";
    }
}

String tree_72(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (ldr_pct <= 80.695000) {
        if (humidity <= 45.500000) {
            if (temp_c <= 32.199999) {
                if (temp_c <= 27.400001) {
                    if (ldr_pct <= 33.625000) {
                        if (mq2_pct <= 54.749999) {
                            return "OSCURO";
                        } else {
                            return "CONTAMINADO";
                        }
                    } else {
                        return "CONTAMINADO";
                    }
                } else {
                    return "OSCURO";
                }
            } else {
                if (mq2_pct <= 71.049999) {
                    return "CALUROSO";
                } else {
                    if (temp_c <= 35.800001) {
                        return "CONTAMINADO";
                    } else {
                        return "ALERTA";
                    }
                }
            }
        } else {
            return "ALERTA";
        }
    } else {
        return "NORMAL";
    }
}

String tree_73(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (temp_c <= 22.750000) {
        return "NORMAL";
    } else {
        if (mq2_pct <= 71.049999) {
            if (temp_c <= 31.850000) {
                return "OSCURO";
            } else {
                return "CALUROSO";
            }
        } else {
            if (humidity <= 45.500000) {
                if (mq2_pct <= 84.899998) {
                    if (humidity <= 44.250000) {
                        return "ALERTA";
                    } else {
                        if (temp_c <= 35.800001) {
                            return "CONTAMINADO";
                        } else {
                            return "ALERTA";
                        }
                    }
                } else {
                    return "CONTAMINADO";
                }
            } else {
                return "ALERTA";
            }
        }
    }
}

String tree_74(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (mq2_pct <= 71.049999) {
        if (temp_c <= 32.199999) {
            if (humidity <= 58.750000) {
                return "OSCURO";
            } else {
                return "NORMAL";
            }
        } else {
            return "CALUROSO";
        }
    } else {
        if (temp_c <= 35.800001) {
            return "CONTAMINADO";
        } else {
            return "ALERTA";
        }
    }
}

String tree_75(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (temp_c <= 22.750000) {
        return "NORMAL";
    } else {
        if (mq2_pct <= 62.429998) {
            if (mq2_pct <= 24.929999) {
                if (temp_c <= 31.850000) {
                    return "OSCURO";
                } else {
                    return "CALUROSO";
                }
            } else {
                return "CALUROSO";
            }
        } else {
            if (temp_c <= 35.700001) {
                return "CONTAMINADO";
            } else {
                return "ALERTA";
            }
        }
    }
}

String tree_76(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (ldr_pct <= 80.695000) {
        if (mq2_pct <= 71.049999) {
            if (mq2_pct <= 24.929999) {
                if (temp_c <= 31.850000) {
                    return "OSCURO";
                } else {
                    return "CALUROSO";
                }
            } else {
                return "CALUROSO";
            }
        } else {
            if (temp_c <= 35.800001) {
                return "CONTAMINADO";
            } else {
                return "ALERTA";
            }
        }
    } else {
        return "NORMAL";
    }
}

String tree_77(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (humidity <= 45.500000) {
        if (temp_c <= 32.199999) {
            if (mq2_pct <= 54.749999) {
                return "OSCURO";
            } else {
                return "CONTAMINADO";
            }
        } else {
            if (humidity <= 44.250000) {
                return "ALERTA";
            } else {
                if (mq2_pct <= 71.049999) {
                    return "CALUROSO";
                } else {
                    if (temp_c <= 35.750000) {
                        return "CONTAMINADO";
                    } else {
                        return "ALERTA";
                    }
                }
            }
        }
    } else {
        if (temp_c <= 29.099999) {
            return "NORMAL";
        } else {
            return "ALERTA";
        }
    }
}

String tree_78(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (temp_c <= 22.750000) {
        return "NORMAL";
    } else {
        if (mq2_pct <= 62.429998) {
            if (temp_c <= 31.850000) {
                return "OSCURO";
            } else {
                return "CALUROSO";
            }
        } else {
            if (temp_c <= 35.800001) {
                return "CONTAMINADO";
            } else {
                return "ALERTA";
            }
        }
    }
}

String tree_79(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (temp_c <= 22.750000) {
        return "NORMAL";
    } else {
        if (temp_c <= 36.300001) {
            if (temp_c <= 32.199999) {
                if (mq2_pct <= 54.749999) {
                    return "OSCURO";
                } else {
                    return "CONTAMINADO";
                }
            } else {
                if (temp_c <= 34.650000) {
                    return "CALUROSO";
                } else {
                    if (temp_c <= 34.750000) {
                        if (mq2_pct <= 55.079998) {
                            return "CALUROSO";
                        } else {
                            return "CONTAMINADO";
                        }
                    } else {
                        if (temp_c <= 35.200001) {
                            if (temp_c <= 34.850000) {
                                return "CALUROSO";
                            } else {
                                return "CONTAMINADO";
                            }
                        } else {
                            return "CALUROSO";
                        }
                    }
                }
            }
        } else {
            if (temp_c <= 37.850000) {
                return "ALERTA";
            } else {
                return "CALUROSO";
            }
        }
    }
}

String tree_80(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (temp_c <= 22.750000) {
        return "NORMAL";
    } else {
        if (mq2_pct <= 62.429998) {
            if (mq2_pct <= 24.929999) {
                if (temp_c <= 32.199999) {
                    return "OSCURO";
                } else {
                    return "CALUROSO";
                }
            } else {
                return "CALUROSO";
            }
        } else {
            if (humidity <= 45.500000) {
                if (humidity <= 44.250000) {
                    return "ALERTA";
                } else {
                    if (mq2_pct <= 84.899998) {
                        if (temp_c <= 35.850000) {
                            return "CONTAMINADO";
                        } else {
                            return "ALERTA";
                        }
                    } else {
                        return "CONTAMINADO";
                    }
                }
            } else {
                return "ALERTA";
            }
        }
    }
}

String tree_81(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (mq2_pct <= 20.745000) {
        return "NORMAL";
    } else {
        if (humidity <= 45.500000) {
            if (mq2_pct <= 62.429998) {
                if (temp_c <= 31.850000) {
                    return "OSCURO";
                } else {
                    return "CALUROSO";
                }
            } else {
                if (temp_c <= 35.800001) {
                    return "CONTAMINADO";
                } else {
                    return "ALERTA";
                }
            }
        } else {
            if (ldr_pct <= 51.000000) {
                return "ALERTA";
            } else {
                return "NORMAL";
            }
        }
    }
}

String tree_82(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (ldr_pct <= 51.000000) {
        if (temp_c <= 32.199999) {
            if (mq2_pct <= 54.749999) {
                return "OSCURO";
            } else {
                return "CONTAMINADO";
            }
        } else {
            if (temp_c <= 36.350000) {
                if (mq2_pct <= 71.049999) {
                    return "CALUROSO";
                } else {
                    return "CONTAMINADO";
                }
            } else {
                if (mq2_pct <= 51.049998) {
                    return "CALUROSO";
                } else {
                    return "ALERTA";
                }
            }
        }
    } else {
        return "NORMAL";
    }
}

String tree_83(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (ldr_pct <= 80.695000) {
        if (humidity <= 45.500000) {
            if (mq2_pct <= 62.429998) {
                if (temp_c <= 31.850000) {
                    return "OSCURO";
                } else {
                    return "CALUROSO";
                }
            } else {
                if (mq2_pct <= 84.899998) {
                    if (temp_c <= 35.800001) {
                        return "CONTAMINADO";
                    } else {
                        return "ALERTA";
                    }
                } else {
                    return "CONTAMINADO";
                }
            }
        } else {
            return "ALERTA";
        }
    } else {
        return "NORMAL";
    }
}

String tree_84(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (temp_c <= 22.750000) {
        return "NORMAL";
    } else {
        if (mq2_pct <= 62.429998) {
            if (mq2_pct <= 24.929999) {
                if (temp_c <= 31.550001) {
                    return "OSCURO";
                } else {
                    return "CALUROSO";
                }
            } else {
                return "CALUROSO";
            }
        } else {
            if (humidity <= 47.750000) {
                if (temp_c <= 35.800001) {
                    return "CONTAMINADO";
                } else {
                    return "ALERTA";
                }
            } else {
                return "ALERTA";
            }
        }
    }
}

String tree_85(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (temp_c <= 22.750000) {
        return "NORMAL";
    } else {
        if (temp_c <= 36.350000) {
            if (ldr_pct <= 33.625000) {
                if (mq2_pct <= 71.049999) {
                    if (mq2_pct <= 24.929999) {
                        if (temp_c <= 32.199999) {
                            return "OSCURO";
                        } else {
                            return "CALUROSO";
                        }
                    } else {
                        return "CALUROSO";
                    }
                } else {
                    return "CONTAMINADO";
                }
            } else {
                return "CONTAMINADO";
            }
        } else {
            if (humidity <= 45.500000) {
                if (humidity <= 44.250000) {
                    return "ALERTA";
                } else {
                    if (temp_c <= 37.850000) {
                        return "ALERTA";
                    } else {
                        return "CALUROSO";
                    }
                }
            } else {
                return "ALERTA";
            }
        }
    }
}

String tree_86(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (ldr_pct <= 80.695000) {
        if (mq2_pct <= 71.049999) {
            if (mq2_pct <= 24.929999) {
                if (temp_c <= 31.850000) {
                    return "OSCURO";
                } else {
                    return "CALUROSO";
                }
            } else {
                return "CALUROSO";
            }
        } else {
            if (temp_c <= 35.700001) {
                return "CONTAMINADO";
            } else {
                return "ALERTA";
            }
        }
    } else {
        return "NORMAL";
    }
}

String tree_87(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (ldr_pct <= 80.695000) {
        if (humidity <= 45.500000) {
            if (mq2_pct <= 71.049999) {
                if (mq2_pct <= 24.929999) {
                    if (temp_c <= 31.850000) {
                        return "OSCURO";
                    } else {
                        return "CALUROSO";
                    }
                } else {
                    return "CALUROSO";
                }
            } else {
                if (humidity <= 44.250000) {
                    return "ALERTA";
                } else {
                    return "CONTAMINADO";
                }
            }
        } else {
            return "ALERTA";
        }
    } else {
        return "NORMAL";
    }
}

String tree_88(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (mq2_pct <= 71.049999) {
        if (temp_c <= 31.850000) {
            if (temp_c <= 22.750000) {
                return "NORMAL";
            } else {
                return "OSCURO";
            }
        } else {
            return "CALUROSO";
        }
    } else {
        if (humidity <= 45.500000) {
            if (temp_c <= 35.850000) {
                return "CONTAMINADO";
            } else {
                return "ALERTA";
            }
        } else {
            return "ALERTA";
        }
    }
}

String tree_89(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (ldr_pct <= 80.695000) {
        if (humidity <= 47.750000) {
            if (mq2_pct <= 71.049999) {
                if (mq2_pct <= 24.929999) {
                    if (temp_c <= 31.850000) {
                        return "OSCURO";
                    } else {
                        return "CALUROSO";
                    }
                } else {
                    return "CALUROSO";
                }
            } else {
                if (humidity <= 43.750000) {
                    return "ALERTA";
                } else {
                    return "CONTAMINADO";
                }
            }
        } else {
            return "ALERTA";
        }
    } else {
        return "NORMAL";
    }
}

String tree_90(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (mq2_pct <= 62.429998) {
        if (humidity <= 58.750000) {
            if (mq2_pct <= 24.929999) {
                if (temp_c <= 32.199999) {
                    return "OSCURO";
                } else {
                    return "CALUROSO";
                }
            } else {
                return "CALUROSO";
            }
        } else {
            return "NORMAL";
        }
    } else {
        if (temp_c <= 35.700001) {
            return "CONTAMINADO";
        } else {
            return "ALERTA";
        }
    }
}

String tree_91(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (ldr_pct <= 80.695000) {
        if (mq2_pct <= 71.049999) {
            if (temp_c <= 31.850000) {
                return "OSCURO";
            } else {
                return "CALUROSO";
            }
        } else {
            if (temp_c <= 35.800001) {
                return "CONTAMINADO";
            } else {
                return "ALERTA";
            }
        }
    } else {
        return "NORMAL";
    }
}

String tree_92(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (humidity <= 45.500000) {
        if (mq2_pct <= 71.049999) {
            if (temp_c <= 32.199999) {
                return "OSCURO";
            } else {
                return "CALUROSO";
            }
        } else {
            if (temp_c <= 35.800001) {
                return "CONTAMINADO";
            } else {
                return "ALERTA";
            }
        }
    } else {
        if (ldr_pct <= 51.000000) {
            return "ALERTA";
        } else {
            return "NORMAL";
        }
    }
}

String tree_93(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (humidity <= 45.500000) {
        if (mq2_pct <= 71.049999) {
            if (mq2_pct <= 24.929999) {
                if (temp_c <= 31.850000) {
                    return "OSCURO";
                } else {
                    return "CALUROSO";
                }
            } else {
                return "CALUROSO";
            }
        } else {
            if (humidity <= 44.250000) {
                return "ALERTA";
            } else {
                if (ldr_pct <= 33.625000) {
                    if (temp_c <= 35.800001) {
                        return "CONTAMINADO";
                    } else {
                        return "ALERTA";
                    }
                } else {
                    return "CONTAMINADO";
                }
            }
        }
    } else {
        if (ldr_pct <= 51.000000) {
            return "ALERTA";
        } else {
            return "NORMAL";
        }
    }
}

String tree_94(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (ldr_pct <= 80.695000) {
        if (mq2_pct <= 62.429998) {
            if (temp_c <= 31.850000) {
                return "OSCURO";
            } else {
                return "CALUROSO";
            }
        } else {
            if (temp_c <= 35.800001) {
                return "CONTAMINADO";
            } else {
                return "ALERTA";
            }
        }
    } else {
        return "NORMAL";
    }
}

String tree_95(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (ldr_pct <= 80.695000) {
        if (mq2_pct <= 71.049999) {
            if (mq2_pct <= 24.929999) {
                if (temp_c <= 32.199999) {
                    return "OSCURO";
                } else {
                    return "CALUROSO";
                }
            } else {
                return "CALUROSO";
            }
        } else {
            if (mq2_pct <= 84.899998) {
                if (temp_c <= 35.700001) {
                    return "CONTAMINADO";
                } else {
                    return "ALERTA";
                }
            } else {
                return "CONTAMINADO";
            }
        }
    } else {
        return "NORMAL";
    }
}

String tree_96(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (humidity <= 45.500000) {
        if (humidity <= 44.250000) {
            return "ALERTA";
        } else {
            if (mq2_pct <= 62.429998) {
                if (temp_c <= 32.199999) {
                    return "OSCURO";
                } else {
                    return "CALUROSO";
                }
            } else {
                return "CONTAMINADO";
            }
        }
    } else {
        if (mq2_pct <= 53.039998) {
            return "NORMAL";
        } else {
            if (mq2_pct <= 84.899998) {
                return "ALERTA";
            } else {
                return "NORMAL";
            }
        }
    }
}

String tree_97(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (ldr_pct <= 80.695000) {
        if (mq2_pct <= 71.049999) {
            if (temp_c <= 32.199999) {
                return "OSCURO";
            } else {
                return "CALUROSO";
            }
        } else {
            if (temp_c <= 35.750000) {
                return "CONTAMINADO";
            } else {
                return "ALERTA";
            }
        }
    } else {
        return "NORMAL";
    }
}

String tree_98(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (mq2_pct <= 62.429998) {
        if (humidity <= 58.750000) {
            if (mq2_pct <= 24.929999) {
                if (temp_c <= 31.850000) {
                    return "OSCURO";
                } else {
                    return "CALUROSO";
                }
            } else {
                return "CALUROSO";
            }
        } else {
            return "NORMAL";
        }
    } else {
        if (temp_c <= 35.800001) {
            if (humidity <= 58.750000) {
                return "CONTAMINADO";
            } else {
                return "NORMAL";
            }
        } else {
            return "ALERTA";
        }
    }
}

String tree_99(float temp_c, float humidity, float ldr_pct, float mq2_pct) {
    if (temp_c <= 36.300001) {
        if (mq2_pct <= 62.429998) {
            if (temp_c <= 31.850000) {
                if (ldr_pct <= 51.000000) {
                    return "OSCURO";
                } else {
                    return "NORMAL";
                }
            } else {
                return "CALUROSO";
            }
        } else {
            if (ldr_pct <= 80.695000) {
                return "CONTAMINADO";
            } else {
                return "NORMAL";
            }
        }
    } else {
        if (humidity <= 45.500000) {
            if (humidity <= 44.250000) {
                return "ALERTA";
            } else {
                if (mq2_pct <= 51.049998) {
                    return "CALUROSO";
                } else {
                    return "ALERTA";
                }
            }
        } else {
            return "ALERTA";
        }
    }
}

String predict_random_forest(float temp_c, float humidity, float ldr_pct, float mq2_pct) {

    int votes_ALERTA = 0;
    int votes_CALUROSO = 0;
    int votes_CONTAMINADO = 0;
    int votes_NORMAL = 0;
    int votes_OSCURO = 0;

    String pred_0 = tree_0(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_0 == "ALERTA") votes_ALERTA++;
    if (pred_0 == "CALUROSO") votes_CALUROSO++;
    if (pred_0 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_0 == "NORMAL") votes_NORMAL++;
    if (pred_0 == "OSCURO") votes_OSCURO++;

    String pred_1 = tree_1(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_1 == "ALERTA") votes_ALERTA++;
    if (pred_1 == "CALUROSO") votes_CALUROSO++;
    if (pred_1 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_1 == "NORMAL") votes_NORMAL++;
    if (pred_1 == "OSCURO") votes_OSCURO++;

    String pred_2 = tree_2(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_2 == "ALERTA") votes_ALERTA++;
    if (pred_2 == "CALUROSO") votes_CALUROSO++;
    if (pred_2 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_2 == "NORMAL") votes_NORMAL++;
    if (pred_2 == "OSCURO") votes_OSCURO++;

    String pred_3 = tree_3(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_3 == "ALERTA") votes_ALERTA++;
    if (pred_3 == "CALUROSO") votes_CALUROSO++;
    if (pred_3 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_3 == "NORMAL") votes_NORMAL++;
    if (pred_3 == "OSCURO") votes_OSCURO++;

    String pred_4 = tree_4(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_4 == "ALERTA") votes_ALERTA++;
    if (pred_4 == "CALUROSO") votes_CALUROSO++;
    if (pred_4 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_4 == "NORMAL") votes_NORMAL++;
    if (pred_4 == "OSCURO") votes_OSCURO++;

    String pred_5 = tree_5(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_5 == "ALERTA") votes_ALERTA++;
    if (pred_5 == "CALUROSO") votes_CALUROSO++;
    if (pred_5 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_5 == "NORMAL") votes_NORMAL++;
    if (pred_5 == "OSCURO") votes_OSCURO++;

    String pred_6 = tree_6(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_6 == "ALERTA") votes_ALERTA++;
    if (pred_6 == "CALUROSO") votes_CALUROSO++;
    if (pred_6 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_6 == "NORMAL") votes_NORMAL++;
    if (pred_6 == "OSCURO") votes_OSCURO++;

    String pred_7 = tree_7(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_7 == "ALERTA") votes_ALERTA++;
    if (pred_7 == "CALUROSO") votes_CALUROSO++;
    if (pred_7 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_7 == "NORMAL") votes_NORMAL++;
    if (pred_7 == "OSCURO") votes_OSCURO++;

    String pred_8 = tree_8(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_8 == "ALERTA") votes_ALERTA++;
    if (pred_8 == "CALUROSO") votes_CALUROSO++;
    if (pred_8 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_8 == "NORMAL") votes_NORMAL++;
    if (pred_8 == "OSCURO") votes_OSCURO++;

    String pred_9 = tree_9(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_9 == "ALERTA") votes_ALERTA++;
    if (pred_9 == "CALUROSO") votes_CALUROSO++;
    if (pred_9 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_9 == "NORMAL") votes_NORMAL++;
    if (pred_9 == "OSCURO") votes_OSCURO++;

    String pred_10 = tree_10(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_10 == "ALERTA") votes_ALERTA++;
    if (pred_10 == "CALUROSO") votes_CALUROSO++;
    if (pred_10 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_10 == "NORMAL") votes_NORMAL++;
    if (pred_10 == "OSCURO") votes_OSCURO++;

    String pred_11 = tree_11(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_11 == "ALERTA") votes_ALERTA++;
    if (pred_11 == "CALUROSO") votes_CALUROSO++;
    if (pred_11 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_11 == "NORMAL") votes_NORMAL++;
    if (pred_11 == "OSCURO") votes_OSCURO++;

    String pred_12 = tree_12(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_12 == "ALERTA") votes_ALERTA++;
    if (pred_12 == "CALUROSO") votes_CALUROSO++;
    if (pred_12 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_12 == "NORMAL") votes_NORMAL++;
    if (pred_12 == "OSCURO") votes_OSCURO++;

    String pred_13 = tree_13(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_13 == "ALERTA") votes_ALERTA++;
    if (pred_13 == "CALUROSO") votes_CALUROSO++;
    if (pred_13 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_13 == "NORMAL") votes_NORMAL++;
    if (pred_13 == "OSCURO") votes_OSCURO++;

    String pred_14 = tree_14(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_14 == "ALERTA") votes_ALERTA++;
    if (pred_14 == "CALUROSO") votes_CALUROSO++;
    if (pred_14 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_14 == "NORMAL") votes_NORMAL++;
    if (pred_14 == "OSCURO") votes_OSCURO++;

    String pred_15 = tree_15(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_15 == "ALERTA") votes_ALERTA++;
    if (pred_15 == "CALUROSO") votes_CALUROSO++;
    if (pred_15 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_15 == "NORMAL") votes_NORMAL++;
    if (pred_15 == "OSCURO") votes_OSCURO++;

    String pred_16 = tree_16(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_16 == "ALERTA") votes_ALERTA++;
    if (pred_16 == "CALUROSO") votes_CALUROSO++;
    if (pred_16 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_16 == "NORMAL") votes_NORMAL++;
    if (pred_16 == "OSCURO") votes_OSCURO++;

    String pred_17 = tree_17(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_17 == "ALERTA") votes_ALERTA++;
    if (pred_17 == "CALUROSO") votes_CALUROSO++;
    if (pred_17 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_17 == "NORMAL") votes_NORMAL++;
    if (pred_17 == "OSCURO") votes_OSCURO++;

    String pred_18 = tree_18(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_18 == "ALERTA") votes_ALERTA++;
    if (pred_18 == "CALUROSO") votes_CALUROSO++;
    if (pred_18 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_18 == "NORMAL") votes_NORMAL++;
    if (pred_18 == "OSCURO") votes_OSCURO++;

    String pred_19 = tree_19(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_19 == "ALERTA") votes_ALERTA++;
    if (pred_19 == "CALUROSO") votes_CALUROSO++;
    if (pred_19 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_19 == "NORMAL") votes_NORMAL++;
    if (pred_19 == "OSCURO") votes_OSCURO++;

    String pred_20 = tree_20(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_20 == "ALERTA") votes_ALERTA++;
    if (pred_20 == "CALUROSO") votes_CALUROSO++;
    if (pred_20 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_20 == "NORMAL") votes_NORMAL++;
    if (pred_20 == "OSCURO") votes_OSCURO++;

    String pred_21 = tree_21(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_21 == "ALERTA") votes_ALERTA++;
    if (pred_21 == "CALUROSO") votes_CALUROSO++;
    if (pred_21 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_21 == "NORMAL") votes_NORMAL++;
    if (pred_21 == "OSCURO") votes_OSCURO++;

    String pred_22 = tree_22(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_22 == "ALERTA") votes_ALERTA++;
    if (pred_22 == "CALUROSO") votes_CALUROSO++;
    if (pred_22 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_22 == "NORMAL") votes_NORMAL++;
    if (pred_22 == "OSCURO") votes_OSCURO++;

    String pred_23 = tree_23(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_23 == "ALERTA") votes_ALERTA++;
    if (pred_23 == "CALUROSO") votes_CALUROSO++;
    if (pred_23 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_23 == "NORMAL") votes_NORMAL++;
    if (pred_23 == "OSCURO") votes_OSCURO++;

    String pred_24 = tree_24(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_24 == "ALERTA") votes_ALERTA++;
    if (pred_24 == "CALUROSO") votes_CALUROSO++;
    if (pred_24 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_24 == "NORMAL") votes_NORMAL++;
    if (pred_24 == "OSCURO") votes_OSCURO++;

    String pred_25 = tree_25(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_25 == "ALERTA") votes_ALERTA++;
    if (pred_25 == "CALUROSO") votes_CALUROSO++;
    if (pred_25 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_25 == "NORMAL") votes_NORMAL++;
    if (pred_25 == "OSCURO") votes_OSCURO++;

    String pred_26 = tree_26(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_26 == "ALERTA") votes_ALERTA++;
    if (pred_26 == "CALUROSO") votes_CALUROSO++;
    if (pred_26 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_26 == "NORMAL") votes_NORMAL++;
    if (pred_26 == "OSCURO") votes_OSCURO++;

    String pred_27 = tree_27(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_27 == "ALERTA") votes_ALERTA++;
    if (pred_27 == "CALUROSO") votes_CALUROSO++;
    if (pred_27 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_27 == "NORMAL") votes_NORMAL++;
    if (pred_27 == "OSCURO") votes_OSCURO++;

    String pred_28 = tree_28(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_28 == "ALERTA") votes_ALERTA++;
    if (pred_28 == "CALUROSO") votes_CALUROSO++;
    if (pred_28 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_28 == "NORMAL") votes_NORMAL++;
    if (pred_28 == "OSCURO") votes_OSCURO++;

    String pred_29 = tree_29(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_29 == "ALERTA") votes_ALERTA++;
    if (pred_29 == "CALUROSO") votes_CALUROSO++;
    if (pred_29 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_29 == "NORMAL") votes_NORMAL++;
    if (pred_29 == "OSCURO") votes_OSCURO++;

    String pred_30 = tree_30(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_30 == "ALERTA") votes_ALERTA++;
    if (pred_30 == "CALUROSO") votes_CALUROSO++;
    if (pred_30 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_30 == "NORMAL") votes_NORMAL++;
    if (pred_30 == "OSCURO") votes_OSCURO++;

    String pred_31 = tree_31(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_31 == "ALERTA") votes_ALERTA++;
    if (pred_31 == "CALUROSO") votes_CALUROSO++;
    if (pred_31 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_31 == "NORMAL") votes_NORMAL++;
    if (pred_31 == "OSCURO") votes_OSCURO++;

    String pred_32 = tree_32(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_32 == "ALERTA") votes_ALERTA++;
    if (pred_32 == "CALUROSO") votes_CALUROSO++;
    if (pred_32 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_32 == "NORMAL") votes_NORMAL++;
    if (pred_32 == "OSCURO") votes_OSCURO++;

    String pred_33 = tree_33(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_33 == "ALERTA") votes_ALERTA++;
    if (pred_33 == "CALUROSO") votes_CALUROSO++;
    if (pred_33 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_33 == "NORMAL") votes_NORMAL++;
    if (pred_33 == "OSCURO") votes_OSCURO++;

    String pred_34 = tree_34(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_34 == "ALERTA") votes_ALERTA++;
    if (pred_34 == "CALUROSO") votes_CALUROSO++;
    if (pred_34 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_34 == "NORMAL") votes_NORMAL++;
    if (pred_34 == "OSCURO") votes_OSCURO++;

    String pred_35 = tree_35(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_35 == "ALERTA") votes_ALERTA++;
    if (pred_35 == "CALUROSO") votes_CALUROSO++;
    if (pred_35 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_35 == "NORMAL") votes_NORMAL++;
    if (pred_35 == "OSCURO") votes_OSCURO++;

    String pred_36 = tree_36(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_36 == "ALERTA") votes_ALERTA++;
    if (pred_36 == "CALUROSO") votes_CALUROSO++;
    if (pred_36 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_36 == "NORMAL") votes_NORMAL++;
    if (pred_36 == "OSCURO") votes_OSCURO++;

    String pred_37 = tree_37(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_37 == "ALERTA") votes_ALERTA++;
    if (pred_37 == "CALUROSO") votes_CALUROSO++;
    if (pred_37 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_37 == "NORMAL") votes_NORMAL++;
    if (pred_37 == "OSCURO") votes_OSCURO++;

    String pred_38 = tree_38(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_38 == "ALERTA") votes_ALERTA++;
    if (pred_38 == "CALUROSO") votes_CALUROSO++;
    if (pred_38 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_38 == "NORMAL") votes_NORMAL++;
    if (pred_38 == "OSCURO") votes_OSCURO++;

    String pred_39 = tree_39(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_39 == "ALERTA") votes_ALERTA++;
    if (pred_39 == "CALUROSO") votes_CALUROSO++;
    if (pred_39 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_39 == "NORMAL") votes_NORMAL++;
    if (pred_39 == "OSCURO") votes_OSCURO++;

    String pred_40 = tree_40(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_40 == "ALERTA") votes_ALERTA++;
    if (pred_40 == "CALUROSO") votes_CALUROSO++;
    if (pred_40 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_40 == "NORMAL") votes_NORMAL++;
    if (pred_40 == "OSCURO") votes_OSCURO++;

    String pred_41 = tree_41(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_41 == "ALERTA") votes_ALERTA++;
    if (pred_41 == "CALUROSO") votes_CALUROSO++;
    if (pred_41 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_41 == "NORMAL") votes_NORMAL++;
    if (pred_41 == "OSCURO") votes_OSCURO++;

    String pred_42 = tree_42(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_42 == "ALERTA") votes_ALERTA++;
    if (pred_42 == "CALUROSO") votes_CALUROSO++;
    if (pred_42 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_42 == "NORMAL") votes_NORMAL++;
    if (pred_42 == "OSCURO") votes_OSCURO++;

    String pred_43 = tree_43(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_43 == "ALERTA") votes_ALERTA++;
    if (pred_43 == "CALUROSO") votes_CALUROSO++;
    if (pred_43 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_43 == "NORMAL") votes_NORMAL++;
    if (pred_43 == "OSCURO") votes_OSCURO++;

    String pred_44 = tree_44(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_44 == "ALERTA") votes_ALERTA++;
    if (pred_44 == "CALUROSO") votes_CALUROSO++;
    if (pred_44 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_44 == "NORMAL") votes_NORMAL++;
    if (pred_44 == "OSCURO") votes_OSCURO++;

    String pred_45 = tree_45(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_45 == "ALERTA") votes_ALERTA++;
    if (pred_45 == "CALUROSO") votes_CALUROSO++;
    if (pred_45 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_45 == "NORMAL") votes_NORMAL++;
    if (pred_45 == "OSCURO") votes_OSCURO++;

    String pred_46 = tree_46(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_46 == "ALERTA") votes_ALERTA++;
    if (pred_46 == "CALUROSO") votes_CALUROSO++;
    if (pred_46 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_46 == "NORMAL") votes_NORMAL++;
    if (pred_46 == "OSCURO") votes_OSCURO++;

    String pred_47 = tree_47(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_47 == "ALERTA") votes_ALERTA++;
    if (pred_47 == "CALUROSO") votes_CALUROSO++;
    if (pred_47 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_47 == "NORMAL") votes_NORMAL++;
    if (pred_47 == "OSCURO") votes_OSCURO++;

    String pred_48 = tree_48(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_48 == "ALERTA") votes_ALERTA++;
    if (pred_48 == "CALUROSO") votes_CALUROSO++;
    if (pred_48 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_48 == "NORMAL") votes_NORMAL++;
    if (pred_48 == "OSCURO") votes_OSCURO++;

    String pred_49 = tree_49(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_49 == "ALERTA") votes_ALERTA++;
    if (pred_49 == "CALUROSO") votes_CALUROSO++;
    if (pred_49 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_49 == "NORMAL") votes_NORMAL++;
    if (pred_49 == "OSCURO") votes_OSCURO++;

    String pred_50 = tree_50(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_50 == "ALERTA") votes_ALERTA++;
    if (pred_50 == "CALUROSO") votes_CALUROSO++;
    if (pred_50 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_50 == "NORMAL") votes_NORMAL++;
    if (pred_50 == "OSCURO") votes_OSCURO++;

    String pred_51 = tree_51(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_51 == "ALERTA") votes_ALERTA++;
    if (pred_51 == "CALUROSO") votes_CALUROSO++;
    if (pred_51 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_51 == "NORMAL") votes_NORMAL++;
    if (pred_51 == "OSCURO") votes_OSCURO++;

    String pred_52 = tree_52(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_52 == "ALERTA") votes_ALERTA++;
    if (pred_52 == "CALUROSO") votes_CALUROSO++;
    if (pred_52 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_52 == "NORMAL") votes_NORMAL++;
    if (pred_52 == "OSCURO") votes_OSCURO++;

    String pred_53 = tree_53(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_53 == "ALERTA") votes_ALERTA++;
    if (pred_53 == "CALUROSO") votes_CALUROSO++;
    if (pred_53 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_53 == "NORMAL") votes_NORMAL++;
    if (pred_53 == "OSCURO") votes_OSCURO++;

    String pred_54 = tree_54(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_54 == "ALERTA") votes_ALERTA++;
    if (pred_54 == "CALUROSO") votes_CALUROSO++;
    if (pred_54 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_54 == "NORMAL") votes_NORMAL++;
    if (pred_54 == "OSCURO") votes_OSCURO++;

    String pred_55 = tree_55(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_55 == "ALERTA") votes_ALERTA++;
    if (pred_55 == "CALUROSO") votes_CALUROSO++;
    if (pred_55 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_55 == "NORMAL") votes_NORMAL++;
    if (pred_55 == "OSCURO") votes_OSCURO++;

    String pred_56 = tree_56(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_56 == "ALERTA") votes_ALERTA++;
    if (pred_56 == "CALUROSO") votes_CALUROSO++;
    if (pred_56 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_56 == "NORMAL") votes_NORMAL++;
    if (pred_56 == "OSCURO") votes_OSCURO++;

    String pred_57 = tree_57(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_57 == "ALERTA") votes_ALERTA++;
    if (pred_57 == "CALUROSO") votes_CALUROSO++;
    if (pred_57 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_57 == "NORMAL") votes_NORMAL++;
    if (pred_57 == "OSCURO") votes_OSCURO++;

    String pred_58 = tree_58(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_58 == "ALERTA") votes_ALERTA++;
    if (pred_58 == "CALUROSO") votes_CALUROSO++;
    if (pred_58 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_58 == "NORMAL") votes_NORMAL++;
    if (pred_58 == "OSCURO") votes_OSCURO++;

    String pred_59 = tree_59(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_59 == "ALERTA") votes_ALERTA++;
    if (pred_59 == "CALUROSO") votes_CALUROSO++;
    if (pred_59 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_59 == "NORMAL") votes_NORMAL++;
    if (pred_59 == "OSCURO") votes_OSCURO++;

    String pred_60 = tree_60(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_60 == "ALERTA") votes_ALERTA++;
    if (pred_60 == "CALUROSO") votes_CALUROSO++;
    if (pred_60 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_60 == "NORMAL") votes_NORMAL++;
    if (pred_60 == "OSCURO") votes_OSCURO++;

    String pred_61 = tree_61(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_61 == "ALERTA") votes_ALERTA++;
    if (pred_61 == "CALUROSO") votes_CALUROSO++;
    if (pred_61 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_61 == "NORMAL") votes_NORMAL++;
    if (pred_61 == "OSCURO") votes_OSCURO++;

    String pred_62 = tree_62(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_62 == "ALERTA") votes_ALERTA++;
    if (pred_62 == "CALUROSO") votes_CALUROSO++;
    if (pred_62 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_62 == "NORMAL") votes_NORMAL++;
    if (pred_62 == "OSCURO") votes_OSCURO++;

    String pred_63 = tree_63(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_63 == "ALERTA") votes_ALERTA++;
    if (pred_63 == "CALUROSO") votes_CALUROSO++;
    if (pred_63 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_63 == "NORMAL") votes_NORMAL++;
    if (pred_63 == "OSCURO") votes_OSCURO++;

    String pred_64 = tree_64(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_64 == "ALERTA") votes_ALERTA++;
    if (pred_64 == "CALUROSO") votes_CALUROSO++;
    if (pred_64 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_64 == "NORMAL") votes_NORMAL++;
    if (pred_64 == "OSCURO") votes_OSCURO++;

    String pred_65 = tree_65(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_65 == "ALERTA") votes_ALERTA++;
    if (pred_65 == "CALUROSO") votes_CALUROSO++;
    if (pred_65 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_65 == "NORMAL") votes_NORMAL++;
    if (pred_65 == "OSCURO") votes_OSCURO++;

    String pred_66 = tree_66(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_66 == "ALERTA") votes_ALERTA++;
    if (pred_66 == "CALUROSO") votes_CALUROSO++;
    if (pred_66 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_66 == "NORMAL") votes_NORMAL++;
    if (pred_66 == "OSCURO") votes_OSCURO++;

    String pred_67 = tree_67(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_67 == "ALERTA") votes_ALERTA++;
    if (pred_67 == "CALUROSO") votes_CALUROSO++;
    if (pred_67 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_67 == "NORMAL") votes_NORMAL++;
    if (pred_67 == "OSCURO") votes_OSCURO++;

    String pred_68 = tree_68(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_68 == "ALERTA") votes_ALERTA++;
    if (pred_68 == "CALUROSO") votes_CALUROSO++;
    if (pred_68 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_68 == "NORMAL") votes_NORMAL++;
    if (pred_68 == "OSCURO") votes_OSCURO++;

    String pred_69 = tree_69(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_69 == "ALERTA") votes_ALERTA++;
    if (pred_69 == "CALUROSO") votes_CALUROSO++;
    if (pred_69 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_69 == "NORMAL") votes_NORMAL++;
    if (pred_69 == "OSCURO") votes_OSCURO++;

    String pred_70 = tree_70(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_70 == "ALERTA") votes_ALERTA++;
    if (pred_70 == "CALUROSO") votes_CALUROSO++;
    if (pred_70 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_70 == "NORMAL") votes_NORMAL++;
    if (pred_70 == "OSCURO") votes_OSCURO++;

    String pred_71 = tree_71(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_71 == "ALERTA") votes_ALERTA++;
    if (pred_71 == "CALUROSO") votes_CALUROSO++;
    if (pred_71 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_71 == "NORMAL") votes_NORMAL++;
    if (pred_71 == "OSCURO") votes_OSCURO++;

    String pred_72 = tree_72(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_72 == "ALERTA") votes_ALERTA++;
    if (pred_72 == "CALUROSO") votes_CALUROSO++;
    if (pred_72 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_72 == "NORMAL") votes_NORMAL++;
    if (pred_72 == "OSCURO") votes_OSCURO++;

    String pred_73 = tree_73(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_73 == "ALERTA") votes_ALERTA++;
    if (pred_73 == "CALUROSO") votes_CALUROSO++;
    if (pred_73 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_73 == "NORMAL") votes_NORMAL++;
    if (pred_73 == "OSCURO") votes_OSCURO++;

    String pred_74 = tree_74(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_74 == "ALERTA") votes_ALERTA++;
    if (pred_74 == "CALUROSO") votes_CALUROSO++;
    if (pred_74 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_74 == "NORMAL") votes_NORMAL++;
    if (pred_74 == "OSCURO") votes_OSCURO++;

    String pred_75 = tree_75(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_75 == "ALERTA") votes_ALERTA++;
    if (pred_75 == "CALUROSO") votes_CALUROSO++;
    if (pred_75 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_75 == "NORMAL") votes_NORMAL++;
    if (pred_75 == "OSCURO") votes_OSCURO++;

    String pred_76 = tree_76(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_76 == "ALERTA") votes_ALERTA++;
    if (pred_76 == "CALUROSO") votes_CALUROSO++;
    if (pred_76 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_76 == "NORMAL") votes_NORMAL++;
    if (pred_76 == "OSCURO") votes_OSCURO++;

    String pred_77 = tree_77(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_77 == "ALERTA") votes_ALERTA++;
    if (pred_77 == "CALUROSO") votes_CALUROSO++;
    if (pred_77 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_77 == "NORMAL") votes_NORMAL++;
    if (pred_77 == "OSCURO") votes_OSCURO++;

    String pred_78 = tree_78(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_78 == "ALERTA") votes_ALERTA++;
    if (pred_78 == "CALUROSO") votes_CALUROSO++;
    if (pred_78 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_78 == "NORMAL") votes_NORMAL++;
    if (pred_78 == "OSCURO") votes_OSCURO++;

    String pred_79 = tree_79(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_79 == "ALERTA") votes_ALERTA++;
    if (pred_79 == "CALUROSO") votes_CALUROSO++;
    if (pred_79 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_79 == "NORMAL") votes_NORMAL++;
    if (pred_79 == "OSCURO") votes_OSCURO++;

    String pred_80 = tree_80(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_80 == "ALERTA") votes_ALERTA++;
    if (pred_80 == "CALUROSO") votes_CALUROSO++;
    if (pred_80 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_80 == "NORMAL") votes_NORMAL++;
    if (pred_80 == "OSCURO") votes_OSCURO++;

    String pred_81 = tree_81(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_81 == "ALERTA") votes_ALERTA++;
    if (pred_81 == "CALUROSO") votes_CALUROSO++;
    if (pred_81 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_81 == "NORMAL") votes_NORMAL++;
    if (pred_81 == "OSCURO") votes_OSCURO++;

    String pred_82 = tree_82(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_82 == "ALERTA") votes_ALERTA++;
    if (pred_82 == "CALUROSO") votes_CALUROSO++;
    if (pred_82 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_82 == "NORMAL") votes_NORMAL++;
    if (pred_82 == "OSCURO") votes_OSCURO++;

    String pred_83 = tree_83(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_83 == "ALERTA") votes_ALERTA++;
    if (pred_83 == "CALUROSO") votes_CALUROSO++;
    if (pred_83 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_83 == "NORMAL") votes_NORMAL++;
    if (pred_83 == "OSCURO") votes_OSCURO++;

    String pred_84 = tree_84(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_84 == "ALERTA") votes_ALERTA++;
    if (pred_84 == "CALUROSO") votes_CALUROSO++;
    if (pred_84 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_84 == "NORMAL") votes_NORMAL++;
    if (pred_84 == "OSCURO") votes_OSCURO++;

    String pred_85 = tree_85(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_85 == "ALERTA") votes_ALERTA++;
    if (pred_85 == "CALUROSO") votes_CALUROSO++;
    if (pred_85 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_85 == "NORMAL") votes_NORMAL++;
    if (pred_85 == "OSCURO") votes_OSCURO++;

    String pred_86 = tree_86(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_86 == "ALERTA") votes_ALERTA++;
    if (pred_86 == "CALUROSO") votes_CALUROSO++;
    if (pred_86 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_86 == "NORMAL") votes_NORMAL++;
    if (pred_86 == "OSCURO") votes_OSCURO++;

    String pred_87 = tree_87(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_87 == "ALERTA") votes_ALERTA++;
    if (pred_87 == "CALUROSO") votes_CALUROSO++;
    if (pred_87 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_87 == "NORMAL") votes_NORMAL++;
    if (pred_87 == "OSCURO") votes_OSCURO++;

    String pred_88 = tree_88(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_88 == "ALERTA") votes_ALERTA++;
    if (pred_88 == "CALUROSO") votes_CALUROSO++;
    if (pred_88 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_88 == "NORMAL") votes_NORMAL++;
    if (pred_88 == "OSCURO") votes_OSCURO++;

    String pred_89 = tree_89(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_89 == "ALERTA") votes_ALERTA++;
    if (pred_89 == "CALUROSO") votes_CALUROSO++;
    if (pred_89 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_89 == "NORMAL") votes_NORMAL++;
    if (pred_89 == "OSCURO") votes_OSCURO++;

    String pred_90 = tree_90(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_90 == "ALERTA") votes_ALERTA++;
    if (pred_90 == "CALUROSO") votes_CALUROSO++;
    if (pred_90 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_90 == "NORMAL") votes_NORMAL++;
    if (pred_90 == "OSCURO") votes_OSCURO++;

    String pred_91 = tree_91(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_91 == "ALERTA") votes_ALERTA++;
    if (pred_91 == "CALUROSO") votes_CALUROSO++;
    if (pred_91 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_91 == "NORMAL") votes_NORMAL++;
    if (pred_91 == "OSCURO") votes_OSCURO++;

    String pred_92 = tree_92(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_92 == "ALERTA") votes_ALERTA++;
    if (pred_92 == "CALUROSO") votes_CALUROSO++;
    if (pred_92 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_92 == "NORMAL") votes_NORMAL++;
    if (pred_92 == "OSCURO") votes_OSCURO++;

    String pred_93 = tree_93(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_93 == "ALERTA") votes_ALERTA++;
    if (pred_93 == "CALUROSO") votes_CALUROSO++;
    if (pred_93 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_93 == "NORMAL") votes_NORMAL++;
    if (pred_93 == "OSCURO") votes_OSCURO++;

    String pred_94 = tree_94(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_94 == "ALERTA") votes_ALERTA++;
    if (pred_94 == "CALUROSO") votes_CALUROSO++;
    if (pred_94 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_94 == "NORMAL") votes_NORMAL++;
    if (pred_94 == "OSCURO") votes_OSCURO++;

    String pred_95 = tree_95(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_95 == "ALERTA") votes_ALERTA++;
    if (pred_95 == "CALUROSO") votes_CALUROSO++;
    if (pred_95 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_95 == "NORMAL") votes_NORMAL++;
    if (pred_95 == "OSCURO") votes_OSCURO++;

    String pred_96 = tree_96(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_96 == "ALERTA") votes_ALERTA++;
    if (pred_96 == "CALUROSO") votes_CALUROSO++;
    if (pred_96 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_96 == "NORMAL") votes_NORMAL++;
    if (pred_96 == "OSCURO") votes_OSCURO++;

    String pred_97 = tree_97(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_97 == "ALERTA") votes_ALERTA++;
    if (pred_97 == "CALUROSO") votes_CALUROSO++;
    if (pred_97 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_97 == "NORMAL") votes_NORMAL++;
    if (pred_97 == "OSCURO") votes_OSCURO++;

    String pred_98 = tree_98(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_98 == "ALERTA") votes_ALERTA++;
    if (pred_98 == "CALUROSO") votes_CALUROSO++;
    if (pred_98 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_98 == "NORMAL") votes_NORMAL++;
    if (pred_98 == "OSCURO") votes_OSCURO++;

    String pred_99 = tree_99(temp_c, humidity, ldr_pct, mq2_pct);
    if (pred_99 == "ALERTA") votes_ALERTA++;
    if (pred_99 == "CALUROSO") votes_CALUROSO++;
    if (pred_99 == "CONTAMINADO") votes_CONTAMINADO++;
    if (pred_99 == "NORMAL") votes_NORMAL++;
    if (pred_99 == "OSCURO") votes_OSCURO++;

    int max_votes = -1;
    String final_prediction = "UNKNOWN";


    if (votes_ALERTA > max_votes) {
        max_votes = votes_ALERTA;
        final_prediction = "ALERTA";
    }

    if (votes_CALUROSO > max_votes) {
        max_votes = votes_CALUROSO;
        final_prediction = "CALUROSO";
    }

    if (votes_CONTAMINADO > max_votes) {
        max_votes = votes_CONTAMINADO;
        final_prediction = "CONTAMINADO";
    }

    if (votes_NORMAL > max_votes) {
        max_votes = votes_NORMAL;
        final_prediction = "NORMAL";
    }

    if (votes_OSCURO > max_votes) {
        max_votes = votes_OSCURO;
        final_prediction = "OSCURO";
    }

    return final_prediction;
}

#endif
