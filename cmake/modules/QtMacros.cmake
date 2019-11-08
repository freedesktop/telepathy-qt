macro(qt_get_moc_flags moc_flags)
    if(QT_VERSION_MAJOR MATCHES 5)
        qt5_get_moc_flags(${moc_flags})
    endif()
endmacro()

macro(qt_create_moc_command infile outfile moc_flags moc_options)
  if(QT_VERSION_MAJOR MATCHES 5)
      qt5_create_moc_command(${infile} ${outfile} "${moc_flags}" "${moc_options}" "" "")
  endif()
endmacro()