#include "parrot/parrot.h"
#include "parrot/api.h"
#include "embed_private.h"

/* HEADERIZER HFILE: include/parrot/api.h */

PARROT_API
Parrot_Int
Parrot_api_pmc_deserialize(Parrot_PMC interp_pmc, Parrot_String fpmc,
        ARGOUT(Parrot_PMC * pmc))
{
    EMBED_API_CALLIN(interp_pmc, interp)
    PMC * const config = Parrot_thaw(interp, fpmc);
    Parrot_set_config_hash_pmc(interp, config);
    EMBED_API_CALLOUT(interp_pmc, interp);
}

PARROT_API
Parrot_Int
Parrot_api_pmc_deserialize_bytes(Parrot_PMC interp_pmc,
        ARGIN(const unsigned char * const fpmc), Parrot_Int length,
        ARGOUT(Parrot_PMC * pmc))
{
    EMBED_API_CALLIN(interp_pmc, interp)
    STRING * const fpmc_str = Parrot_str_new_init(interp, fpmc, length,
        Parrot_binary_encoding_ptr, PObj_external_FLAG);
    PMC * const config = Parrot_thaw(interp, fpmc_str);
    Parrot_set_config_hash_pmc(interp, config);
    EMBED_API_CALLOUT(interp_pmc, interp);
}

PARROT_API
Parrot_Int
Parrot_api_pmc_null(Parrot_PMC interp_pmc, ARGMOD(Parrot_PMC *pmctonull))
{
    EMBED_API_CALLIN(interp_pmc, interp)
    *pmctonull = PMCNULL;
    EMBED_API_CALLOUT(interp_pmc, interp);
}

PARROT_API
Parrot_Int
Parrot_api_pmc_get_string(Parrot_PMC interp_pmc, Parrot_PMC pmc,
        ARGOUT(Parrot_String * str))
{
    EMBED_API_CALLIN(interp_pmc, interp)
    *str = VTABLE_get_string(interp, pmc);
    EMBED_API_CALLOUT(interp_pmc, interp)
}

PARROT_API
Parrot_Int
Parrot_api_pmc_get_integer(Parrot_PMC interp_pmc, Parrot_PMC pmc,
        ARGOUT(Parrot_Int * value))
{
    EMBED_API_CALLIN(interp_pmc, interp)
    *value = VTABLE_get_integer(interp, pmc);
    EMBED_API_CALLOUT(interp_pmc, interp)
}

PARROT_API
Parrot_Int
Parrot_api_pmc_get_float(Parrot_PMC interp_pmc, Parrot_PMC pmc,
        ARGOUT(Parrot_Float * value))
{
    EMBED_API_CALLIN(interp_pmc, interp)
    *value = VTABLE_get_number(interp, pmc);
    EMBED_API_CALLOUT(interp_pmc, interp)
}

PARROT_API
Parrot_Int
Parrot_api_pmc_set_string(Parrot_PMC interp_pmc, Parrot_PMC pmc,
    Parrot_String value)
{
    EMBED_API_CALLIN(interp_pmc, interp)
    VTABLE_set_string_native(interp, pmc, value);
    EMBED_API_CALLOUT(interp_pmc, interp)
}

PARROT_API
Parrot_Int
Parrot_api_pmc_set_integer(Parrot_PMC interp_pmc, Parrot_PMC pmc,
    Parrot_Int value)
{
    EMBED_API_CALLIN(interp_pmc, interp)
    VTABLE_set_integer_native(interp, pmc, value);
    EMBED_API_CALLOUT(interp_pmc, interp)
}

PARROT_API
Parrot_Int
Parrot_api_pmc_set_float(Parrot_PMC interp_pmc, Parrot_PMC pmc,
    Parrot_Float value)
{
    EMBED_API_CALLIN(interp_pmc, interp)
    VTABLE_set_number_native(interp, pmc, value);
    EMBED_API_CALLOUT(interp_pmc, interp)
}

PARROT_API
Parrot_Int
Parrot_api_add_exception_handler(Parrot_PMC interp_pmc, Parrot_PMC handler)
{
    EMBED_API_CALLIN(interp_pmc, interp)
    Parrot_cx_add_handler(interp, handler);
    EMBED_API_CALLOUT(interp_pmc, interp)
}

PARROT_API
Parrot_Int
Parrot_api_call_sub(Parrot_PMC interp_pmc, Parrot_PMC sub_pmc,
        ARGIN(const char * signature), ...)
{
    EMBED_API_CALLIN(interp_pmc, interp)
    va_list args;
    PMC  *call_obj;
    const char *arg_sig, *ret_sig;

    PMC  * const old_call_obj = Parrot_pcc_get_signature(interp,
        CURRENT_CONTEXT(interp));
    Parrot_pcc_split_signature_string(signature, &arg_sig, &ret_sig);

    va_start(args, signature);
    call_obj = Parrot_pcc_build_call_from_varargs(interp, PMCNULL,
        arg_sig, &args);

    Parrot_pcc_invoke_from_sig_object(interp, sub_pmc, call_obj);
    call_obj = Parrot_pcc_get_signature(interp, CURRENT_CONTEXT(interp));
    Parrot_pcc_fill_params_from_varargs(interp, call_obj, ret_sig, &args,
            PARROT_ERRORS_RESULT_COUNT_FLAG);
    va_end(args);
    Parrot_pcc_set_signature(interp, CURRENT_CONTEXT(interp), old_call_obj);
    EMBED_API_CALLOUT(interp_pmc, interp)
}
