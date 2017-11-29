#ifndef __pyOCCT_Common_Header__
#define __pyOCCT_Common_Header__

// Pybind
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
namespace py = pybind11;

// Use opencascade::handle as holder type for Standard_Transient types
#include <Standard_Handle.hxx>
PYBIND11_DECLARE_HOLDER_TYPE(T, opencascade::handle<T>, true);
// PYBIND11_DECLARE_HOLDER_TYPE(T, T*);

// Hack for a fix where the fully qualified name is not found
using opencascade::handle;

// Use boost::shared_ptr for some SMESH iterators
#include <boost/shared_ptr.hpp>
PYBIND11_DECLARE_HOLDER_TYPE(T, boost::shared_ptr<T>);

// Deleter template for mixed holder types with public/hidden destructors
template<typename T> struct Deleter { void operator() (T *o) const { delete o; } };

#endif