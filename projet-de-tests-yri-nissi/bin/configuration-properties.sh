export YRI_SD_MEALY_MACHINE_COMPILER_FULL_PATH=${HOME}/yri_sd_runtime_verif_lang/yri_sd_runtime_verif_lang_COMPILER__generation.sh
export YRI_SD_MEALY_MACHINE_SPEC_FOLDER_FULL_PATH=${HOME}/yri-db-runtime-verif/projet-de-tests-yri-nissi/sd-mealy-machine-specs
export YRI_DB_RUNTIME_VERIF_SRC_FULL_PATH=${HOME}/yri-db-runtime-verif/src

YRI_CURRENT_PROJECT_DIRECTORY=${PWD}
YRI_CURRENT_PROJECT_DIRECTORY_BASE=${YRI_CURRENT_PROJECT_DIRECTORY%%/bin}

#echo "* ${YRI_CURRENT_PROJECT_DIRECTORY_BASE}"

export COMPILER_GENERATED_OUTPUT_FOLDER_FULL_PATH=${YRI_CURRENT_PROJECT_DIRECTORY_BASE}/runtime-monitor-cplusplus-classes-GENERATED

#echo "**** ${COMPILER_GENERATED_OUTPUT_FOLDER_FULL_PATH}"

