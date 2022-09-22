// Generated by gmmproc 2.66.2 -- DO NOT MODIFY!


#include <glibmm.h>

#include <giomm/outputstream.h>
#include <giomm/private/outputstream_p.h>


/* Copyright (C) 2007 The gtkmm Development Team
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
#include <glibmm/exceptionhandler.h>
#include <giomm/slot_async.h>

namespace Gio
{

void
OutputStream::write_async(const void* buffer, gsize count, const SlotAsyncReady& slot,
  const Glib::RefPtr<Cancellable>& cancellable, int io_priority)
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  auto slot_copy = new SlotAsyncReady(slot);

  g_output_stream_write_async(gobj(), buffer, count, io_priority, Glib::unwrap(cancellable),
    &SignalProxy_async_callback, slot_copy);
}

void
OutputStream::write_async(
  const void* buffer, gsize count, const SlotAsyncReady& slot, int io_priority)
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  auto slot_copy = new SlotAsyncReady(slot);

  g_output_stream_write_async(
    gobj(), buffer, count, io_priority, nullptr, &SignalProxy_async_callback, slot_copy);
}

void
OutputStream::write_all_async(const void* buffer, gsize count, const SlotAsyncReady& slot,
  const Glib::RefPtr<Cancellable>& cancellable, int io_priority)
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  auto slot_copy = new SlotAsyncReady(slot);

  g_output_stream_write_all_async(gobj(), buffer, count, io_priority, Glib::unwrap(cancellable),
    &SignalProxy_async_callback, slot_copy);
}

void
OutputStream::write_all_async(
  const void* buffer, gsize count, const SlotAsyncReady& slot, int io_priority)
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  auto slot_copy = new SlotAsyncReady(slot);

  g_output_stream_write_all_async(
    gobj(), buffer, count, io_priority, nullptr, &SignalProxy_async_callback, slot_copy);
}

void
OutputStream::splice_async(const Glib::RefPtr<InputStream>& source, const SlotAsyncReady& slot,
  const Glib::RefPtr<Cancellable>& cancellable, OutputStreamSpliceFlags flags, int io_priority)
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  auto slot_copy = new SlotAsyncReady(slot);

  g_output_stream_splice_async(gobj(), Glib::unwrap(source),
    static_cast<GOutputStreamSpliceFlags>(flags), io_priority, Glib::unwrap(cancellable),
    &SignalProxy_async_callback, slot_copy);
}

void
OutputStream::splice_async(const Glib::RefPtr<InputStream>& source, const SlotAsyncReady& slot,
  OutputStreamSpliceFlags flags, int io_priority)
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  auto slot_copy = new SlotAsyncReady(slot);

  g_output_stream_splice_async(gobj(), Glib::unwrap(source),
    static_cast<GOutputStreamSpliceFlags>(flags), io_priority, nullptr, &SignalProxy_async_callback,
    slot_copy);
}

void
OutputStream::flush_async(
  const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, int io_priority)
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  auto slot_copy = new SlotAsyncReady(slot);

  g_output_stream_flush_async(
    gobj(), io_priority, Glib::unwrap(cancellable), &SignalProxy_async_callback, slot_copy);
}

void
OutputStream::flush_async(const SlotAsyncReady& slot, int io_priority)
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  auto slot_copy = new SlotAsyncReady(slot);

  g_output_stream_flush_async(gobj(), io_priority, nullptr, &SignalProxy_async_callback, slot_copy);
}

void
OutputStream::close_async(
  const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, int io_priority)
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  auto slot_copy = new SlotAsyncReady(slot);

  g_output_stream_close_async(
    gobj(), io_priority, Glib::unwrap(cancellable), &SignalProxy_async_callback, slot_copy);
}

void
OutputStream::close_async(const SlotAsyncReady& slot, int io_priority)
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  auto slot_copy = new SlotAsyncReady(slot);

  g_output_stream_close_async(gobj(), io_priority, nullptr, &SignalProxy_async_callback, slot_copy);
}

gssize
OutputStream::write(const std::string& buffer, const Glib::RefPtr<Cancellable>& cancellable)
{
  GError* gerror = nullptr;
  gssize retvalue = g_output_stream_write(
    gobj(), buffer.data(), buffer.size(), Glib::unwrap(cancellable), &(gerror));
  if (gerror)
    ::Glib::Error::throw_exception(gerror);

  return retvalue;
}

gssize
OutputStream::write(const std::string& buffer)
{
  GError* gerror = nullptr;
  gssize retvalue = g_output_stream_write(gobj(), buffer.data(), buffer.size(), nullptr, &(gerror));
  if (gerror)
    ::Glib::Error::throw_exception(gerror);

  return retvalue;
}

bool
OutputStream::write_all(
  const std::string& buffer, gsize& bytes_written, const Glib::RefPtr<Cancellable>& cancellable)
{
  GError* gerror = nullptr;
  bool retvalue = g_output_stream_write_all(
    gobj(), buffer.data(), buffer.size(), &(bytes_written), Glib::unwrap(cancellable), &(gerror));
  if (gerror)
    ::Glib::Error::throw_exception(gerror);

  return retvalue;
}

bool
OutputStream::write_all(const std::string& buffer, gsize& bytes_written)
{
  GError* gerror = nullptr;
  bool retvalue = g_output_stream_write_all(
    gobj(), buffer.data(), buffer.size(), &(bytes_written), nullptr, &(gerror));
  if (gerror)
    ::Glib::Error::throw_exception(gerror);

  return retvalue;
}

void
OutputStream::write_bytes_async(const Glib::RefPtr<const Glib::Bytes>& bytes,
  const SlotAsyncReady& slot, const Glib::RefPtr<Cancellable>& cancellable, int io_priority)
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  SlotAsyncReady* slot_copy = new SlotAsyncReady(slot);

  g_output_stream_write_bytes_async(gobj(), const_cast<GBytes*>(Glib::unwrap(bytes)), io_priority,
    Glib::unwrap(cancellable), &SignalProxy_async_callback, slot_copy);
}

void
OutputStream::write_bytes_async(
  const Glib::RefPtr<const Glib::Bytes>& bytes, const SlotAsyncReady& slot, int io_priority)
{
  // Create a copy of the slot.
  // A pointer to it will be passed through the callback's data parameter
  // and deleted in the callback.
  SlotAsyncReady* slot_copy = new SlotAsyncReady(slot);

  g_output_stream_write_bytes_async(gobj(), const_cast<GBytes*>(Glib::unwrap(bytes)), io_priority,
    nullptr, &SignalProxy_async_callback, slot_copy);
}

gssize
OutputStream::splice(const Glib::RefPtr<InputStream>& source,
  const Glib::RefPtr<Cancellable>& cancellable, OutputStreamSpliceFlags flags)
{
  GError* gerror = nullptr;
  gssize retvalue = g_output_stream_splice(gobj(), Glib::unwrap(source),
    ((GOutputStreamSpliceFlags)(flags)), Glib::unwrap(cancellable), &(gerror));
  if (gerror)
    ::Glib::Error::throw_exception(gerror);

  return retvalue;
}

gssize
OutputStream::splice(const Glib::RefPtr<InputStream>& source, OutputStreamSpliceFlags flags)
{
  GError* gerror = nullptr;
  gssize retvalue = g_output_stream_splice(
    gobj(), Glib::unwrap(source), ((GOutputStreamSpliceFlags)(flags)), nullptr, &(gerror));
  if (gerror)
    ::Glib::Error::throw_exception(gerror);

  return retvalue;
}

} // namespace Gio

namespace
{
} // anonymous namespace


namespace Glib
{

Glib::RefPtr<Gio::OutputStream> wrap(GOutputStream* object, bool take_copy)
{
  return Glib::RefPtr<Gio::OutputStream>( dynamic_cast<Gio::OutputStream*> (Glib::wrap_auto ((GObject*)(object), take_copy)) );
  //We use dynamic_cast<> in case of multiple inheritance.
}

} /* namespace Glib */


namespace Gio
{


/* The *_Class implementation: */

const Glib::Class& OutputStream_Class::init()
{
  if(!gtype_) // create the GType if necessary
  {
    // Glib::Class has to know the class init function to clone custom types.
    class_init_func_ = &OutputStream_Class::class_init_function;

    // This is actually just optimized away, apparently with no harm.
    // Make sure that the parent type has been created.
    //CppClassParent::CppObjectType::get_type();

    // Create the wrapper type, with the same class/instance size as the base type.
    register_derived_type(g_output_stream_get_type());

    // Add derived versions of interfaces, if the C type implements any interfaces:

  }

  return *this;
}


void OutputStream_Class::class_init_function(void* g_class, void* class_data)
{
  const auto klass = static_cast<BaseClassType*>(g_class);
  CppClassParent::class_init_function(klass, class_data);


}


Glib::ObjectBase* OutputStream_Class::wrap_new(GObject* object)
{
  return new OutputStream((GOutputStream*)object);
}


/* The implementation: */

GOutputStream* OutputStream::gobj_copy()
{
  reference();
  return gobj();
}

OutputStream::OutputStream(const Glib::ConstructParams& construct_params)
:
  Glib::Object(construct_params)
{

}

OutputStream::OutputStream(GOutputStream* castitem)
:
  Glib::Object((GObject*)(castitem))
{}


OutputStream::OutputStream(OutputStream&& src) noexcept
: Glib::Object(std::move(src))
{}

OutputStream& OutputStream::operator=(OutputStream&& src) noexcept
{
  Glib::Object::operator=(std::move(src));
  return *this;
}


OutputStream::~OutputStream() noexcept
{}


OutputStream::CppClassType OutputStream::outputstream_class_; // initialize static member

GType OutputStream::get_type()
{
  return outputstream_class_.init().get_type();
}


GType OutputStream::get_base_type()
{
  return g_output_stream_get_type();
}


OutputStream::OutputStream()
:
  // Mark this class as non-derived to allow C++ vfuncs to be skipped.
  Glib::ObjectBase(nullptr),
  Glib::Object(Glib::ConstructParams(outputstream_class_.init()))
{
  

}

gssize OutputStream::write(const void* buffer, gsize count, const Glib::RefPtr<Cancellable>& cancellable)
{
  GError* gerror = nullptr;
  gssize retvalue = g_output_stream_write(gobj(), buffer, count, const_cast<GCancellable*>(Glib::unwrap(cancellable)), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

gssize OutputStream::write(const void* buffer, gsize count)
{
  GError* gerror = nullptr;
  gssize retvalue = g_output_stream_write(gobj(), buffer, count, nullptr, &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

bool OutputStream::write_all(const void* buffer, gsize count, gsize& bytes_written, const Glib::RefPtr<Cancellable>& cancellable)
{
  GError* gerror = nullptr;
  bool retvalue = g_output_stream_write_all(gobj(), buffer, count, &(bytes_written), const_cast<GCancellable*>(Glib::unwrap(cancellable)), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

bool OutputStream::write_all(const void* buffer, gsize count, gsize& bytes_written)
{
  GError* gerror = nullptr;
  bool retvalue = g_output_stream_write_all(gobj(), buffer, count, &(bytes_written), nullptr, &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

gssize OutputStream::write_bytes(const Glib::RefPtr<const Glib::Bytes>& bytes, const Glib::RefPtr<Cancellable>& cancellable)
{
  GError* gerror = nullptr;
  gssize retvalue = g_output_stream_write_bytes(gobj(), const_cast<GBytes*>(Glib::unwrap<Glib::Bytes>(bytes)), const_cast<GCancellable*>(Glib::unwrap(cancellable)), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

gssize OutputStream::write_bytes(const Glib::RefPtr<const Glib::Bytes>& bytes)
{
  GError* gerror = nullptr;
  gssize retvalue = g_output_stream_write_bytes(gobj(), const_cast<GBytes*>(Glib::unwrap<Glib::Bytes>(bytes)), nullptr, &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

gssize OutputStream::write_bytes_finish(const Glib::RefPtr<AsyncResult>& result)
{
  GError* gerror = nullptr;
  gssize retvalue = g_output_stream_write_bytes_finish(gobj(), Glib::unwrap(result), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

bool OutputStream::flush(const Glib::RefPtr<Cancellable>& cancellable)
{
  GError* gerror = nullptr;
  bool retvalue = g_output_stream_flush(gobj(), const_cast<GCancellable*>(Glib::unwrap(cancellable)), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

bool OutputStream::flush()
{
  GError* gerror = nullptr;
  bool retvalue = g_output_stream_flush(gobj(), nullptr, &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

bool OutputStream::close(const Glib::RefPtr<Cancellable>& cancellable)
{
  GError* gerror = nullptr;
  bool retvalue = g_output_stream_close(gobj(), const_cast<GCancellable*>(Glib::unwrap(cancellable)), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

bool OutputStream::close()
{
  GError* gerror = nullptr;
  bool retvalue = g_output_stream_close(gobj(), nullptr, &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

gssize OutputStream::write_finish(const Glib::RefPtr<AsyncResult>& result)
{
  GError* gerror = nullptr;
  gssize retvalue = g_output_stream_write_finish(gobj(), Glib::unwrap(result), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

bool OutputStream::write_all_finish(const Glib::RefPtr<AsyncResult>& result, gsize& bytes_written)
{
  GError* gerror = nullptr;
  bool retvalue = g_output_stream_write_all_finish(gobj(), Glib::unwrap(result), &(bytes_written), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

gssize OutputStream::splice_finish(const Glib::RefPtr<AsyncResult>& result)
{
  GError* gerror = nullptr;
  gssize retvalue = g_output_stream_splice_finish(gobj(), Glib::unwrap(result), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

bool OutputStream::flush_finish(const Glib::RefPtr<AsyncResult>& result)
{
  GError* gerror = nullptr;
  bool retvalue = g_output_stream_flush_finish(gobj(), Glib::unwrap(result), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

bool OutputStream::close_finish(const Glib::RefPtr<AsyncResult>& result)
{
  GError* gerror = nullptr;
  bool retvalue = g_output_stream_close_finish(gobj(), Glib::unwrap(result), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

bool OutputStream::is_closed() const
{
  return g_output_stream_is_closed(const_cast<GOutputStream*>(gobj()));
}

bool OutputStream::is_closing() const
{
  return g_output_stream_is_closing(const_cast<GOutputStream*>(gobj()));
}

bool OutputStream::has_pending() const
{
  return g_output_stream_has_pending(const_cast<GOutputStream*>(gobj()));
}

bool OutputStream::set_pending()
{
  GError* gerror = nullptr;
  bool retvalue = g_output_stream_set_pending(gobj(), &(gerror));
  if(gerror)
    ::Glib::Error::throw_exception(gerror);
  return retvalue;
}

void OutputStream::clear_pending()
{
  g_output_stream_clear_pending(gobj());
}


} // namespace Gio

