#!/bin/bash

# Script de test du parsing minirt
# Teste les fichiers valides et invalides

MINIRT="./minirt"
TESTS_VALID=("test_valid_simple.rt" "test_valid_multiple_objects.rt" "test_valid_all_ratio_ranges.rt")
TESTS_INVALID=("test_invalid_no_ambient.rt" "test_invalid_no_camera.rt" "test_invalid_no_light.rt" \
               "test_invalid_ambient_out_of_range.rt" "test_invalid_ambient_twice.rt" \
               "test_invalid_rgb_out_of_range.rt" "test_invalid_camera_dir_not_normalized.rt" \
               "test_invalid_camera_dir_zero.rt" "test_invalid_fov_out_of_range.rt" \
               "test_invalid_light_brightness_out_of_range.rt" "test_invalid_sphere_diameter_zero.rt" \
               "test_invalid_plane_normal_zero.rt" "test_invalid_cylinder_axis_zero.rt" \
               "test_invalid_camera_wrong_fields.rt" "test_invalid_unknown_identifier.rt")

echo "=============================================="
echo "  TESTS DE PARSING - miniRT"
echo "=============================================="
echo ""

# Tester les fichiers valides (doivent lancer MinilibX = success)
echo ">> TESTS VALIDES (doivent s'exécuter sans erreur)"
echo ""
for file in "${TESTS_VALID[@]}"; do
    echo -n "Testing: $file ... "
    if timeout 1 $MINIRT "$file" 2>&1 | grep -q "Error"; then
        echo "❌ FAILED (unexpected error)"
    else
        echo "✅ PASSED (no error)"
    fi
done

echo ""
echo "=============================================="
echo ">> TESTS INVALIDES (doivent afficher 'Error')"
echo ""
for file in "${TESTS_INVALID[@]}"; do
    echo -n "Testing: $file ... "
    OUTPUT=$(timeout 1 $MINIRT "$file" 2>&1)
    if echo "$OUTPUT" | head -1 | grep -q "Error"; then
        ERROR_MSG=$(echo "$OUTPUT" | head -2 | tail -1)
        echo "✅ PASSED"
        echo "   Error: $ERROR_MSG"
    else
        echo "❌ FAILED (should show Error)"
    fi
done

echo ""
echo "=============================================="
echo ">> TEST D'EXTENSION"
echo ""
echo -n "Testing: minirt.c (should fail) ... "
OUTPUT=$(timeout 1 $MINIRT "minirt.c" 2>&1)
if echo "$OUTPUT" | head -1 | grep -q "Error"; then
    echo "✅ PASSED"
else
    echo "❌ FAILED"
fi

echo ""
echo ">> TEST D'ARGUMENTS"
echo ""
echo -n "Testing: no args (should fail) ... "
OUTPUT=$($MINIRT 2>&1)
if echo "$OUTPUT" | head -1 | grep -q "Error"; then
    echo "✅ PASSED"
else
    echo "❌ FAILED"
fi

echo ""
echo "=============================================="
echo "  FIN DES TESTS"
echo "=============================================="
