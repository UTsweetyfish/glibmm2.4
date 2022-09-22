// Generated by gmmproc 2.66.2 -- DO NOT MODIFY!


#include <glibmm.h>

#include <giomm/socketaddress.h>
#include <giomm/private/socketaddress_p.h>


/* Copyright (C) 2007 The giomm Development Team
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <gio/gio.h>
#include <glibmm/error.h>
#include <giomm/asyncresult.h>
#include <giomm/slot_async.h>

namespace Gio
{
} // namespace Gio

namespace
{
} // anonymous namespace


namespace Glib
{

Glib::RefPtr<Gio::SocketAddress> wrap(GSocketAddress* object, bool take_copy)
{
  return Glib::RefPtr<Gio::SocketAddress>( dynamic_cast<Gio::SocketAddress*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

const Glib::Class& SocketAddress_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &SocketAddress_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_socket_address_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:
  SocketConnectable::add_interface(get_type());

  }

  return *this;
}


void SocketAddress_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


Glib::ObjectBase* SocketAddress_Class::wrap_new(GObject* object)
{
  return new SocketAddress((GSocketAddress*)object);
}


/* The implementation: */

GSocketAddress* SocketAddress::gobj_copy()
{
  reference();
  return gobj();
}

SocketAddress::SocketAddress(const Glib::ConstructParams& construct_params)
:
  Glib::Object(construct_params)
{

}

SocketAddress::SocketAddress(GSocketAddress* castitem)
:
  Glib::Object((GObject*)(castitem))
{}


SocketAddress::SocketAddress(SocketAddress&& src) noexcept
: Glib::Object(std::move(src))
  , SocketConnectable(std::move(src))
{}

SocketAddress& SocketAddress::operator=(SocketAddress&& src) noexcept
{
  Glib::Object::operator=(std::move(src));
  SocketConnectable::operator=(std::move(src));
  return *this;
}


SocketAddress::~SocketAddress() noexcept
{}


SocketAddress::CppClassType SocketAddress::socketaddress_class_; // initialize static member

GType SocketAddress::get_type()
{
  return socketaddress_class_.init().get_type();
}


GType SocketAddress::get_base_type()
{
  return g_socket_address_get_type();
}


Glib::RefPtr<SocketAddress> SocketAddress::create(gpointer native, gsize len)
{
  return Glib::wrap(g_socket_address_new_from_native(native, len));
}

SocketFamily SocketAddress::get_family() const
{
  return ((SocketFamily)(g_socket_address_get_family(const_cast<GSocketAddress*>(gobj()))));
}

bool SocketAddress::to_native(gpointer dest, gsize destlen)
{
  GError* gerror = nullptr;
  bool retvalue = g_socket_address_to_native(gobj(), dest, destlen, &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

gssize SocketAddress::get_native_size() const
{
  return g_socket_address_get_native_size(const_cast<GSocketAddress*>(gobj()));
}


Glib::PropertyProxy_ReadOnly< Glib::RefPtr<SocketFamily> > SocketAddress::property_family() const
{
  return Glib::PropertyProxy_ReadOnly< Glib::RefPtr<SocketFamily> >(this, "family");
}


} // namespace Gio

