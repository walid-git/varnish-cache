
.. _vcl-types(7):

==========
VCL-Types
==========


.. _ACL:

ACL

	Type name: ACL

	Convertible to string: yes

.. 	tostringmeth: "((\v1)->name)"

.. 	global_pfx: "vrt_acl"


.. _BACKEND:

BACKEND

	Type name: BACKEND

	Methods:

	  * resolve:  Return the effective backend.

	Convertible to string: yes

.. 	global_pfx: "vgc_backend"

.. 	tostringmeth: "VRT_BACKEND_string(\v1)"


.. _BLOB:

BLOB

	Type name: BLOB

	Convertible to string: yes

	Body form: yes

.. 	tostringmeth: "VRT_BLOB_string(ctx, \v1)"


.. _BODY:

BODY

	Type name: BODY

.. 	noindent


.. _BOOL:

BOOL

	Type name: BOOL

	Convertible to string: yes

.. 	tostringmeth: "VRT_BOOL_string(\v1)"


.. _BYTES:

BYTES

	Type name: BYTES

	Convertible to string: yes

	Multiply type: REAL

.. 	tostringmeth: "VRT_INT_string(ctx, \v1)"


.. _DURATION:

DURATION

	Type name: DURATION

	Convertible to string: yes

	Multiply type: REAL

.. 	tostringmeth: "VRT_REAL_string(ctx, \v1)"


.. _ENUM:

ENUM

	Type name: ENUM

	Convertible to string: yes

.. 	tostringmeth: ""


.. _HEADER:

HEADER

	Type name: HEADER

	Convertible to string: yes

.. 	tostringmeth: "VRT_GetHdr(ctx, \v1)"


.. _HTTP:

HTTP

	Type name: HTTP


.. _INSTANCE:

INSTANCE

	Type name: INSTANCE

.. 	global_pfx: "vo"


.. _INT:

INT

	Type name: INT

	Multiply type: INT

	Convertible to string: yes

.. 	tostringmeth: "VRT_INT_string(ctx, \v1)"


.. _IP:

IP

	Type name: IP

	Convertible to string: yes

.. 	tostringmeth: "VRT_IP_string(ctx, \v1)"


.. _PROBE:

PROBE

	Type name: PROBE

.. 	global_pfx: "vgc_probe"


.. _REAL:

REAL

	Type name: REAL

	Convertible to string: yes

	Multiply type: REAL

.. 	tostringmeth: "VRT_REAL_string(ctx, \v1)"


.. _REGEX:

REGEX

	Type name: REGEX


.. _STEVEDORE:

STEVEDORE

	Type name: STEVEDORE

	Methods:

	  * free_space: Returns the number of bytes available in the stevedore.

	  * used_space: Returns the numbers of bytes used by the stevedore.

	  * happy: Returns a boolean indicating the Health status for the stevedore.

	Convertible to string: yes

.. 	tostringmeth: "VRT_STEVEDORE_string(\v1)"


.. _STRING:

STRING

	Type name: STRING

.. 	stringform


.. _STRANDS:

STRANDS

	Type name: STRANDS

	Convertible to string: yes

.. 	tostringmeth: "VRT_STRANDS_string(ctx,\v+\n\v1\v-\n)"

.. 	stringform


.. _STRINGS:

STRINGS

	Type name: STRINGS

	Methods:

	  * upper: Returns an uppercase representation of the string.

	  * lower: Returns a lowercase representation of the string.

	Convertible to string: yes

	Body form: yes

.. 	tostringmeth: ""


.. _SUB:

SUB

	Type name: SUB

.. 	global_pfx: "VGC_function"


.. _TIME:

TIME

	Type name: TIME

	Convertible to string: yes

.. 	tostringmeth: "VRT_TIME_string(ctx, \v1)"


.. _VCL:

VCL

	Type name: VCL


.. _VOID:

VOID

	Type name: VOID
