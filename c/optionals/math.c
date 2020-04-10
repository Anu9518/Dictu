#include "math.h"
#include "../vm.h"
#include <math.h>

static Value averageNative(VM *vm, int argCount, Value *args) {
    double average = 0;

    if (argCount == 0) {
        return NUMBER_VAL(0);
    } else if (argCount == 1 && IS_LIST(args[0])) {
        ObjList *list = AS_LIST(args[0]);
        argCount = list->values.count;
        args = list->values.values;
    }

    for (int i = 0; i < argCount; ++i) {
        Value value = args[i];
        if (!IS_NUMBER(value)) {
            runtimeError(vm, "A non-number value passed to average()");
            return EMPTY_VAL;
        }
        average = average + AS_NUMBER(value);
    }

    return NUMBER_VAL(average / argCount);
}

static Value floorNative(VM *vm, int argCount, Value *args) {
    if (argCount != 1) {
        runtimeError(vm, "floor() takes 1 argument (%d given).", argCount);
        return EMPTY_VAL;
    }

    if (!IS_NUMBER(args[0])) {
        runtimeError(vm, "A non-number value passed to floor()");
        return EMPTY_VAL;
    }


    return NUMBER_VAL(floor(AS_NUMBER(args[0])));
}

static Value roundNative(VM *vm, int argCount, Value *args) {
    if (argCount != 1) {
        runtimeError(vm, "round() takes 1 argument (%d given).", argCount);
        return EMPTY_VAL;
    }

    if (!IS_NUMBER(args[0])) {
        runtimeError(vm, "A non-number value passed to round()");
        return EMPTY_VAL;
    }


    return NUMBER_VAL(round(AS_NUMBER(args[0])));
}

static Value ceilNative(VM *vm, int argCount, Value *args) {
    if (argCount != 1) {
        runtimeError(vm, "ceil() takes 1 argument (%d given).", argCount);
        return EMPTY_VAL;
    }

    if (!IS_NUMBER(args[0])) {
        runtimeError(vm, "A non-number value passed to ceil()");
        return EMPTY_VAL;
    }


    return NUMBER_VAL(ceil(AS_NUMBER(args[0])));
}

static Value absNative(VM *vm, int argCount, Value *args) {
    if (argCount != 1) {
        runtimeError(vm, "abs() takes 1 argument (%d given).", argCount);
        return EMPTY_VAL;
    }

    if (!IS_NUMBER(args[0])) {
        runtimeError(vm, "A non-number value passed to abs()");
        return EMPTY_VAL;
    }

    double absValue = AS_NUMBER(args[0]);

    if (absValue < 0)
        return NUMBER_VAL(absValue * -1);
    return NUMBER_VAL(absValue);
}

static Value sumNative(VM *vm, int argCount, Value *args) {
    double sum = 0;

    if (argCount == 0) {
        return NUMBER_VAL(0);
    } else if (argCount == 1 && IS_LIST(args[0])) {
        ObjList *list = AS_LIST(args[0]);
        argCount = list->values.count;
        args = list->values.values;
    }

    for (int i = 0; i < argCount; ++i) {
        Value value = args[i];
        if (!IS_NUMBER(value)) {
            runtimeError(vm, "A non-number value passed to sum()");
            return EMPTY_VAL;
        }
        sum = sum + AS_NUMBER(value);
    }

    return NUMBER_VAL(sum);
}

static Value minNative(VM *vm, int argCount, Value *args) {
    if (argCount == 0) {
        return NUMBER_VAL(0);
    } else if (argCount == 1 && IS_LIST(args[0])) {
        ObjList *list = AS_LIST(args[0]);
        argCount = list->values.count;
        args = list->values.values;
    }

    double minimum = AS_NUMBER(args[0]);

    for (int i = 1; i < argCount; ++i) {
        Value value = args[i];
        if (!IS_NUMBER(value)) {
            runtimeError(vm, "A non-number value passed to min()");
            return EMPTY_VAL;
        }

        double current = AS_NUMBER(value);

        if (minimum > current) {
            minimum = current;
        }
    }

    return NUMBER_VAL(minimum);
}

static Value maxNative(VM *vm, int argCount, Value *args) {
    if (argCount == 0) {
        return NUMBER_VAL(0);
    } else if (argCount == 1 && IS_LIST(args[0])) {
        ObjList *list = AS_LIST(args[0]);
        argCount = list->values.count;
        args = list->values.values;
    }

    double maximum = AS_NUMBER(args[0]);

    for (int i = 1; i < argCount; ++i) {
        Value value = args[i];
        if (!IS_NUMBER(value)) {
            runtimeError(vm, "A non-number value passed to max()");
            return EMPTY_VAL;
        }

        double current = AS_NUMBER(value);

        if (maximum < current) {
            maximum = current;
        }
    }

    return NUMBER_VAL(maximum);
}

void createMathsClass(VM *vm) {
    ObjString *name = copyString(vm, "Math", 4);
    push(vm, OBJ_VAL(name));
    ObjClassNative *klass = newClassNative(vm, name);
    push(vm, OBJ_VAL(klass));

    /**
     * Define Math methods
     */
    defineNative(vm, &klass->methods, "average", averageNative);
    defineNative(vm, &klass->methods, "floor", floorNative);
    defineNative(vm, &klass->methods, "round", roundNative);
    defineNative(vm, &klass->methods, "ceil", ceilNative);
    defineNative(vm, &klass->methods, "abs", absNative);
    defineNative(vm, &klass->methods, "max", maxNative);
    defineNative(vm, &klass->methods, "min", minNative);
    defineNative(vm, &klass->methods, "sum", sumNative);

    /**
     * Define Math properties
     */
    defineNativeProperty(vm, &klass->properties, "PI", NUMBER_VAL(3.14159265358979));
    defineNativeProperty(vm, &klass->properties, "e", NUMBER_VAL(2.71828182845905));

    tableSet(vm, &vm->globals, name, OBJ_VAL(klass));
    pop(vm);
    pop(vm);
}