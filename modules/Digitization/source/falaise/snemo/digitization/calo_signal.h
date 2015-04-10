// snemo/digitization/calo_signal.h
// Author(s): Yves LEMIERE <lemiere@lpccaen.in2p3.fr>
// Author(s): Guillaume OLIVIERO <goliviero@lpccaen.in2p3.fr>

#ifndef FALAISE_DIGITIZATION_PLUGIN_SNEMO_DIGITIZATION_CALO_SIGNAL_H
#define FALAISE_DIGITIZATION_PLUGIN_SNEMO_DIGITIZATION_CALO_SIGNAL_H

// Standard library :
#include <bitset>

// Third party:
// - Bayeux/geomtools :
#include <bayeux/geomtools/base_hit.h>
// - Bayeux/datatools :
#include <datatools/clhep_units.h>

namespace snemo {
  
  namespace digitization {

    /// \brief The calo tracker signal
    class calo_signal : public geomtools::base_hit
    {
    public : 

      static const double DELAYED_PM_TIME = 130.6;

      /// Default constructor
      calo_signal();

      /// Destructor
      virtual ~calo_signal();
      
      /// Return the const time with the photomultiplier delay
      double get_signal_time() const;
     
      // Set the time with the photomultiplier delay
      void set_signal_time(const double & signal_time_);

      /// Return the const energy
      double get_energy() const;
     
      // Set the energy
      void set_energy(const double & energy_);

      /// Check the lock status
      bool is_locked() const;

      /// Lock 
      void lock();

      /// Unlock
      void unlock();

      /// Check if the internal data of calo signal is valid
      bool is_valid() const;

      /// Reset the internal data of calo signal
      void reset();

      /// Smart print
      virtual void tree_dump(std::ostream      & a_out    = std::clog,
														 const std::string & a_title  = "",
														 const std::string & a_indent = "",
														 bool a_inherit               = false) const;

    protected : 

      /// Check if a calo signal is available
      void _check();

    private : 

      bool _locked_; //!< Calorimeter signal lock flag
			double _signal_time_;
      double _energy_; //!< Energy 
      
      // DATATOOLS_SERIALIZATION_DECLARATION();
      
    };

  } // end of namespace digitization

} // end of namespace snemo

#endif /* FALAISE_DIGITIZATION_PLUGIN_SNEMO_DIGITIZATION_CALO_SIGNAL_H */

/* 
** Local Variables: --
** mode: c++ --
** c-file-style: "gnu" --
** tab-width: 2 --
** End: --
*/